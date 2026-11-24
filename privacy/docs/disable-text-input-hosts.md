# Disable Text Input Hosts

`ctfmon.exe` is the classic CTF (Collaborative Translation Framework) loader, it's started in the users session by the Text Input Management Service (`TextInputManagementService`, `TabSvc.dll`, `CCtfmonProcessInfo`). It seems to handle [IME](https://learn.microsoft.com/en-us/windows/apps/develop/input/input-method-editors) (Input Method Editor) support, language/input profiles, language bar/input indicator, and [keyboard layout switching](https://noverse.dev/docs/win-config/peripheral/keyboard-values/). 

Note that renaming that binary will break input in of start menu/MS store/UWP apps etc.

`TextInputHost.exe` is the modern text input host (from `MicrosoftWindows.Client.CBS`), it seems to get used (on demand) through the `InputApp` registration when opening modern input parts such as `Win+.`, `Win+V`, touch keyboard, handwriting, voice typing, and so on.

