# System Informer

Since [system informer](https://systeminformer.io/) is a lot better than the default task manager, it's recommended to replace it. It e.g. uses the clock cycle counter instead of the clock interval timer (which the normal taskmanager uses), which would show CPU consumption of threads that have such a short execution time that task manager would show them as `0%`.

Enable `Theme support` (dark mode) and disable `Check for updates automatically` with:
```powershell
(gc "$env:appdata\SystemInformer\settings.xml") -replace '(?<=<setting name="ProcessHacker\.UpdateChecker\.PromptStart">)\d(?=</setting>)','0' -replace '(?<=<setting name="EnableThemeSupport">)\d(?=</setting>)','1' | sc "$appdata\SystemInformer\settings.xml"
```

