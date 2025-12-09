# (C) 2025 Noverse. All Rights Reserved.
# This PY is used for WinConfig
# https://github.com/5Noxi
# https://discord.gg/E2ybG4j9jU

from __future__ import annotations
import argparse, json, os, re, shutil, subprocess, sys, urllib.request, zipfile
try:
    import winreg
except ImportError:
    winreg = None
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, List, Sequence

HEX_PATTERN = re.compile(r"0x[0-9A-Fa-f]+")
LOCATION_PATTERN = re.compile(r"PCI\s+bus\s+(?P<bus>\d+),\s*device\s+(?P<device>\d+),\s*function\s+(?P<function>\d+)", re.IGNORECASE,)

class RwError(RuntimeError):
    """rw error"""

def get_default_rw_path() -> Path:
    base = Path(os.environ.get("LOCALAPPDATA", str(Path.home())))
    return base / "Noverse" / "IMOD" / "RwPortable" / "Win64" / "Portable" / "Rw.exe"

def rw_binary(rw_path: Path) -> None:
    if rw_path.exists():
        return

    nv_root = rw_path
    if len(rw_path.parents) >= 3:
        nv_root = rw_path.parents[2]
    else:
        nv_root = rw_path.parent

    nv_root.mkdir(parents=True, exist_ok=True)
    archive_path = nv_root / "RwPortableX64V1.7.zip"
    url = "http://rweverything.com/downloads/RwPortableX64V1.7.zip"
    print("[~] rw.exe not found, downloading portable package")
    urllib.request.urlretrieve(url, archive_path)

    with zipfile.ZipFile(archive_path) as zf:
        zf.extractall(nv_root)

    extracted_exe = nv_root / "Win64" / "Portable" / "Rw.exe"
    if extracted_exe.exists() and extracted_exe.resolve() != rw_path.resolve():
        rw_path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(extracted_exe, rw_path)
        print(f"[+] Placed rw.exe at {rw_path}")
    try:
        archive_path.unlink()
    except OSError:
        pass
    if not rw_path.exists():
        raise RwError(f"[!] Failed to place rw.exe at {rw_path}")


def kill_rw_processes() -> None:
    if os.name != "nt":
        return
    subprocess.run(
        ["taskkill", "/IM", "Rw.exe", "/F", "/T"],
        capture_output=True,
        text=True,
    )

def _startup_script_path() -> Path:
    local_app = Path(os.environ.get("LOCALAPPDATA", str(Path.home())))
    dest_dir = local_app / "Noverse" / "IMOD"
    dest_dir.mkdir(parents=True, exist_ok=True)
    return dest_dir / Path(__file__).name


def install_startup_task(raw_args: Sequence[str]) -> None:
    python_path = Path(sys.executable).resolve()
    script_source = Path(__file__).resolve()
    dest_script = _startup_script_path()
    if script_source.resolve() != dest_script.resolve():
        shutil.copy2(script_source, dest_script)

    filtered = [arg for arg in raw_args if arg != "--startup"]
    cmd_args = [str(python_path), str(dest_script)] + filtered
    task_cmd = subprocess.list2cmdline(cmd_args)
    task_name = "Noverse-IMOD"
    result = subprocess.run(["schtasks", "/Create", "/SC", "ONLOGON", "/RL", "HIGHEST", "/TN", task_name, "/TR", task_cmd, "/F", ], capture_output=True, text=True)
    if result.returncode != 0:
        raise SystemExit(f"Failed to create scheduled task (tsch error {result.returncode})")
    print(f"[+] Scheduled task '{task_name}' created to run at logon")

def vulnerable_driver_blocklist() -> None:
    if os.name != "nt" or winreg is None:
        return
    key_path = r"SYSTEM\CurrentControlSet\Control\CI\Config"
    value_name = "VulnerableDriverBlocklistEnable"
    try:
        try:
            key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, key_path, 0, winreg.KEY_SET_VALUE | winreg.KEY_QUERY_VALUE)
        except FileNotFoundError:
            key = winreg.CreateKey(winreg.HKEY_LOCAL_MACHINE, key_path)
        with key:
            try:
                current_val, _ = winreg.QueryValueEx(key, value_name)
            except FileNotFoundError:
                current_val = None
            if current_val != 0:
                print("[~] Disabling VulnerableDriverBlocklistEnable")
                winreg.SetValueEx(key, value_name, 0, winreg.REG_DWORD, 0)
    except PermissionError as exc:
        raise SystemExit("Failed to modify VulnerableDriverBlocklistEnable (missing privileges)") from exc

@dataclass
class Bdf:
    bus: int
    device: int
    function: int

    def __str__(self) -> str:
        return f"{self.bus:02x}:{self.device:02x}.{self.function:x}"

class ExecRw:
    def __init__(self, rw_path: Path, verbose: bool = False) -> None:
        self.rw_path = rw_path
        self.verbose = verbose

    def _call(self, command: str) -> str:
        args = [str(self.rw_path), "/NoLogo", f"/Command={command}", "/Stdout"]
        if self.verbose:
            print(f"[rw] {command}")
        proc = subprocess.run(args, capture_output=True, text=True, check=False,)
        output = (proc.stdout or "") + (proc.stderr or "")
        output = output.strip()
        if proc.returncode:
            raise RwError(f"rw.exe command '{command}' failed: {output}")
        if self.verbose and output:
            print(f"[rw] {output}")
        return output

    def _read_hex(self, command: str) -> int:
        payload = self._call(command)
        matches = HEX_PATTERN.findall(payload)
        if not matches:
            raise RwError(f"rw.exe output did not contain a hex value: {payload}")
        return int(matches[-1], 16)

    def get_xhci(self, index: int) -> int:
        return self._read_hex(f"FPciClass 0x0C0330 0x{index:X}")

    def read_pci_dword(self, bdf: Bdf, offset: int) -> int:
        return self._read_hex(f"RPCI32 0x{bdf.bus:X} 0x{bdf.device:X} 0x{bdf.function:X} 0x{offset:X}")

    def read_mmio_dword(self, address: int) -> int:
        return self._read_hex(f"R32 0x{address:X}")

    def write_mmio_dword(self, address: int, value: int) -> None:
        self._call(f"W32 0x{address:X} 0x{value:X}")


def parse_bdf_string(raw: str) -> Bdf:
    try:
        bus_part, devfun = raw.split(":")
        dev_part, fun_part = devfun.split(".")
        return Bdf(int(bus_part, 0), int(dev_part, 0), int(fun_part, 0))
    except (ValueError, AttributeError) as exc:
        raise argparse.ArgumentTypeError(f"Invalid BDF '{raw}', expected format BB:DD.F") from exc


def decode_bdf(value: int) -> Bdf:
    bus = (value >> 8) & 0xFF
    device = (value >> 3) & 0x1F
    function = value & 0x7
    return Bdf(bus, device, function)


def parse_interval(value: str) -> int:
    try:
        parsed = int(value, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError("Interval must be an integer value") from exc
    if parsed < 0 or parsed > 0xFFFF:
        raise argparse.ArgumentTypeError("Interval must be within 0..65535 (250ns units)")
    return parsed

def resolve_mmio_base(rw: ExecRw, bdf: Bdf) -> int:
    bar0 = rw.read_pci_dword(bdf, 0x10)
    if bar0 & 0x1:
        raise RwError("BAR0 reports I/O space, expected MMIO base")
    is_64bit = bool(bar0 & 0x4)
    base = bar0 & ~0xF
    if is_64bit:
        bar1 = rw.read_pci_dword(bdf, 0x14)
        base |= bar1 << 32
    return base


def read_runtime_base(rw: ExecRw, operational_base: int) -> int:
    rtsoff = rw.read_mmio_dword(operational_base + 0x18)
    runtime_offset = rtsoff & ~0x1F
    return operational_base + runtime_offset


def read_max_interrupters(rw: ExecRw, operational_base: int) -> int:
    hcsparams1 = rw.read_mmio_dword(operational_base + 0x04)
    max_intrs = (hcsparams1 >> 8) & 0x7FF
    if max_intrs == 0:
        raise RwError("HCSPARAMS1 reported zero interrupters")
    return max_intrs

def determine_interrupters(max_intrs: int, requested: Sequence[int] | None) -> List[int]:
    if not requested:
        return list(range(max_intrs))
    unique = sorted(set(requested))
    for intr in unique:
        if intr < 0 or intr >= max_intrs:
            raise RwError(f"Requested Interrupter {intr} is outside the valid range 0..{max_intrs-1}")
    return unique


def imod_address(runtime_base: int, interrupter: int) -> int:
    return runtime_base + 0x24 + (interrupter * 0x20)

def disable_interrupt_moderation(rw: ExecRw, runtime_base: int, interrupters: Iterable[int], *, interval: int, no_write: bool) -> None:
    target_interval = interval & 0xFFFF
    desired_value = target_interval | (target_interval << 16)
    for intr in interrupters:
        address = imod_address(runtime_base, intr)
        current = rw.read_mmio_dword(address)
        prefix = "[+]" if current != desired_value else "[-]"
        if current == desired_value:
            print(
                f"{prefix} Interrupter {intr}: IMOD @ 0x{address:016X} currently 0x{current:08X} "
                f"(already {target_interval})"
            )
            continue
        if no_write:
            print(
                f"{prefix} Interrupter {intr}: IMOD @ 0x{address:016X} currently 0x{current:08X} "
                f"(no-write: target {target_interval})"
            )
            continue
        rw.write_mmio_dword(address, desired_value)
        new_value = rw.read_mmio_dword(address)
        if (new_value & 0xFFFF) != target_interval:
            raise RwError(f"Failed to program IMOD for interrupter {intr}, read-back 0x{new_value:08X}")
        print(
            f"{prefix} Interrupter {intr}: IMOD @ 0x{address:016X} currently 0x{new_value:08X} "
            f"(set to {target_interval})"
        )

def get_bdf(rw: ExecRw, index: int) -> Bdf:
    raw = rw.get_xhci(index)
    if raw == 0xFFFF:
        raise RwError("rw.exe could not locate an xHCI controller with FPciClass")
    return decode_bdf(raw)


def get_all_bdfs(rw: ExecRw) -> List[Bdf]:
    controllers: List[Bdf] = []
    index = 0
    while True:
        raw = rw.get_xhci(index)
        if raw == 0xFFFF:
            break
        controllers.append(decode_bdf(raw))
        index += 1
    return controllers

def powershell_json(script: str) -> Any:
    try:
        completed = subprocess.run(["powershell.exe", "-c", script], capture_output=True, text=True, check=False)
    except FileNotFoundError as exc:
        raise RwError("powershell.exe is missing?") from exc

    if completed.returncode != 0:
        raise RwError(f"PowerShell query failed ({completed.returncode}): {completed.stderr.strip()}")

    payload = completed.stdout.strip()
    if not payload:
        return []

    data = json.loads(payload)
    if isinstance(data, dict):
        return [data]
    return data


def parse_location_string(location: str | None) -> Bdf | None:
    if not location:
        return None
    match = LOCATION_PATTERN.search(location)
    if not match:
        return None
    return Bdf(bus=int(match.group("bus")), device=int(match.group("device")), function=int(match.group("function")))


def get_controller_instance(bdf: Bdf) -> dict[str, Any] | None:
    script = r"""
$controllers = Get-WmiObject -Class Win32_USBController
$result = foreach ($c in $controllers) {
    $loc = (Get-PnpDeviceProperty -InstanceId $c.PNPDeviceID -Key 'DEVPKEY_Device_LocationInfo' -ErrorAction SilentlyContinue).Data
    [PSCustomObject]@{
        Name = $c.Name
        PNPDeviceID = $c.PNPDeviceID
        Location = $loc
    }
}
$result | ConvertTo-Json -Depth 3 -Compress
"""
    controllers = powershell_json(script)
    for controller in controllers:
        location_bdf = parse_location_string(controller.get("Location"))
        if location_bdf and location_bdf == bdf:
            return controller
    return None

def list_attached_devices(pnp_device_id: str) -> list[dict[str, Any]]:
    escaped = pnp_device_id.replace("'", "''")
    script = f"""
$controller = Get-WmiObject -Class Win32_USBController | ? {{ $_.PNPDeviceID -eq '{escaped}' }}
if ($controller) {{
    $devices = $controller.GetRelated("Win32_PnPEntity")
    $result = foreach ($d in $devices) {{
        [PSCustomObject]@{{
            Name = $d.Name
            DeviceID = $d.DeviceID
            Status = $d.Status
        }}
    }}
    $result | ConvertTo-Json -Depth 3 -Compress
}}
"""
    devices = powershell_json(script)
    return devices if isinstance(devices, list) else []


def print_attached_devices(bdf: Bdf) -> list[str]:
    try:
        controller = get_controller_instance(bdf)
    except RwError as exc:
        print(f"    Unable to enumerate attached devices: {exc}")
        return []

    if not controller:
        print("    No matching Windows USB controller metadata found for this device")
        return []

    print(f"    Windows controller: {controller.get('Name')} ({controller.get('PNPDeviceID')})")

    try:
        devices = list_attached_devices(controller["PNPDeviceID"])
    except RwError as exc:
        print(f"    Unable to enumerate attached devices: {exc}")
        return []

    controller_device_id = (controller.get("PNPDeviceID") or "").upper()
    devices = [
        device
        for device in devices
        if (device.get("DeviceID") or "").upper() != controller_device_id
    ]

    if not devices:
        print("      (No attached USB devices reported via Win32_USBControllerDevice)")
        return []

    print("      Attached devices:")
    attached_names: list[str] = []
    for device in sorted(devices, key=lambda d: d.get("Name") or ""):
        name = device.get("Name") or "(unknown USB device)"
        device_id = device.get("DeviceID") or "(no device id)"
        status = device.get("Status") or "Unknown"
        print(f"        {name} [{device_id}] status={status}")
        attached_names.append(name)
    return attached_names


def process_controller(bdf: Bdf, runner: ExecRw, args: argparse.Namespace) -> None:
    print(f"[~] Using xHCI controller @ {bdf}")

    mmio_base = resolve_mmio_base(runner, bdf)
    print(f"    Operational/Register base: 0x{mmio_base:016X}")

    runtime_base = read_runtime_base(runner, mmio_base)
    print(f"    Runtime Register base: 0x{runtime_base:016X}")

    max_intrs = read_max_interrupters(runner, mmio_base)
    print(f"    Controller has {max_intrs} Interrupter Register Sets")

    print_attached_devices(bdf)

    interrupters = determine_interrupters(max_intrs, args.interrupter)
    disable_interrupt_moderation(runner, runtime_base, interrupters, interval=args.interval, no_write=args.no_write)
    print("[+] Done")

def parse_args(argv: Sequence[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="[xHCI IMOD] Disable Interrupter Moderation via rw.exe")
    parser.add_argument(
        "--rw-path",
        type=Path,
        default=get_default_rw_path(),
        help="Path to rw.exe (defaults to auto downloaded portable build under %%LOCALAPPDATA%%\\Noverse)",
    )
    group = parser.add_mutually_exclusive_group()
    group.add_argument(
        "--bdf",
        type=parse_bdf_string,
        help="Explicit xHCI PCI address in BB:DD.F (hex) format",
    )
    group.add_argument(
        "--xhci-index",
        type=int,
        help="If multiple xHCI controllers exist, choose the Nth device (default 0)",
    )
    group.add_argument(
        "--all",
        action="store_true",
        help="Iterate over every xHCI controller returned by rw.exe FPciClass",
    )
    parser.add_argument(
        "--interrupter",
        "-i",
        type=int,
        action="append",
        help="Interrupter ID to modify (default: all reported by HCSPARAMS1) "
        "Repeat to target multiple specific IDs",
    )
    parser.add_argument(
        "--interval",
        type=parse_interval,
        default=0,
        help="IMOD interval value (0 disables throttling). Units are 250ns, range 0-65535 (0xFFFF)",
    )
    parser.add_argument(
        "--no-write",
        action="store_true",
        help="Show the registers that would be cleared without writing them",
    )
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Display rw.exe commands and responses",
    )
    parser.add_argument(
        "--startup",
        action="store_true",
        help="Adds a scheduled task that reruns this command",
    )
    return parser.parse_args(argv)


def main(argv: Sequence[str]) -> int:
    raw_args = list(argv)
    args = parse_args(argv)

    if args.startup:
        install_startup_task(raw_args)
    vulnerable_driver_blocklist()
    kill_rw_processes()
    rw_path = args.rw_path
    try:
        rw_binary(rw_path)
    except Exception as exc:
        raise SystemExit(f"Unable to prepare rw.exe at {rw_path}: {exc}") from exc
    runner = ExecRw(rw_path, verbose=args.verbose)
    if args.all:
        controllers = get_all_bdfs(runner)
        if not controllers:
            raise SystemExit("No xHCI controllers reported via FPciClass")
    elif args.bdf:
        controllers = [args.bdf]
    else:
        index = args.xhci_index if args.xhci_index is not None else 0
        controllers = [get_bdf(runner, index)]
    for bdf in controllers:
        process_controller(bdf, runner, args)
    return 0

if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))