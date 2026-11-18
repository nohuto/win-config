# Clear Quick Access Lists

Quick access shows recent files and pinned folders in File Explorer. Clearing these files will reset your quick access pins to default state. Windows recreates these files as you use File Explorer and apps again.

It clears both Quick Access Jump List folders:
```c
%APPDATA%\Microsoft\Windows\Recent\AutomaticDestinations\*
%APPDATA%\Microsoft\Windows\Recent\CustomDestinations\*
```

