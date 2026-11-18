# Debloated Driver

Complete [NVIDIA driver preparation tool](https://github.com/nohuto/win-config/blob/main/nvidia/assets/scripts/NVIDIA-Tool.ps1).

### Main Menu

- `1` - Debloat driver (includes optional DDU clean uninstall)
- `2` - Install driver directly  

### Driver Debloat Option

- Opens [www.techpowerup.com | nvidia-drivers](https://www.techpowerup.com/download/nvidia-geforce-graphics-drivers/)
- Removes all non-essential folders except `Display.Driver`, `NVI2`, `setup.cfg`, and `setup.exe`
- Cleans up `.xml` and `.cfg` files by removing telemetry, EULA, and web-link entries
- Miscellaenous theme configurations

### Optional DDU Cleanup

Downloads [`NV-DDU.zip`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.zip) and [`NV-DDU.ps1`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.ps1), enables Safe Boot, and reboots.

### Driver Installation

Runs `setup.exe`.

