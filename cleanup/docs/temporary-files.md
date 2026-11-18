# Temporary Files

Per user temporary files are saved in `%TEMP%`, global files under `%WINDIR%\Temp`. Some installers never delete leftovers, so those can pollute the folder. Anything that is still used will be skipped.

Paths removed:
```c
%TEMP%\*
%WINDIR%\Temp\*
```

