# (C) 2026 Noverse.
# https://github.com/nohuto
# https://discord.noverse.dev

import subprocess
from pathlib import Path

root = Path(__file__).resolve().parent
exe = root / "d3dreg.exe"

def run(args):
    return subprocess.run([exe, *args], stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                          text=True, errors="replace")

listed = run(["-keys"])
listed.check_returncode()
keys = sorted(set(listed.stdout.split()), key=str.casefold)

def render(names):
    result = run([f"{name}=?" for name in names])
    if not result.returncode or len(names) == 1:
        return result.stdout
    middle = len(names) // 2
    return render(names[:middle]) + render(names[middle:])

output = "".join(render(keys[i:i + 200]) for i in range(0, len(keys), 200))
(root / "parameters.txt").write_text(output.lstrip(), encoding="utf-8")
