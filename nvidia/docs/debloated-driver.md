# Debloated Driver

Complete [NVIDIA driver preparation tool](https://github.com/nohuto/win-config/blob/main/nvidia/assets/scripts/NVIDIA-Tool.ps1).

### Main Menu

- `1` - Debloat driver (includes optional DDU clean uninstall)
- `2` - Install driver directly  

### Driver Debloat Option

- Needs 7Z (`C:\Program Files\7-Zip\7z.exe`)
- Opens [www.techpowerup.com | nvidia-drivers](https://www.techpowerup.com/download/nvidia-geforce-graphics-drivers/), asks for the driver path (leave it blank for the `desktop-win10`/`notebook-win10` installer in `Downloads`), extracts it to `Desktop\NV-Driver`
- Removes everything except `Display.Driver`, `NVI2`, `setup.cfg`, `setup.exe`

### Optional DDU Cleanup

Downloads [`NV-DDU.zip`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.zip) and [`NV-DDU.ps1`](https://github.com/nohuto/files/releases/download/driver/NV-DDU.ps1) to the desktop, enables Safe Boot, and reboots.

### Driver Installation

Runs `setup.exe`.

