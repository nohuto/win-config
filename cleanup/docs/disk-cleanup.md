# Disk Cleanup

Every option in *Disk Cleanup* is a handler under `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\VolumeCaches`.

> "*Ten days after you upgrade to Windows, your previous version of Windows is automatically deleted from your PC. If you need to free up drive space sooner and are confident your files and settings are correct, you can safely delete the previous Windows installation yourself.*
>
> *If it's been fewer than 10 days since you upgraded to Windows, your previous version of Windows will be listed as a system file you can delete. You can delete it, but keep in mind that you'll be deleting your Windows.old folder, which contains files that give you the option to go back to your previous version of Windows. If you delete your previous version of Windows, this can't be undone (you won't be able to go back to your previous version of Windows).*"
>
> — Microsoft, [Delete your previous version of Windows](https://support.microsoft.com/en-us/windows/delete-your-previous-version-of-windows-f8b26680-e083-c710-b757-7567d69dbb74)

| Name | Handler key | Deletes |
| --- | --- | --- |
| Temporary Setup Files | `Active Setup Temp Folders` | `*.tmp` in `%WINDIR%\msdownld.tmp` and `<drive>:\msdownld.tmp` |
| Catalog files for the Content Indexer | `Content Indexer Cleaner` | `<drive>:\Catalog.wci` |
| DirectX Shader Cache | `D3D Shader Cache` | `%LOCALAPPDATA%\D3DSCache` (`D3DSCache.dll`) |
| Delivery Optimization Files | `Delivery Optimization Files` | Delivery Optimization cache (`domgmt.dll`) |
| Device driver packages | `Device Driver Packages` | older versions of driver packages in the driver store, newest stays (`pnpclean.dll`) |
| Diagnostic data viewer database files | `Diagnostic Data Viewer database files` | `%PROGRAMDATA%\Microsoft\Diagnosis\EventTranscript` |
| Downloaded Program Files | `Downloaded Program Files` | ActiveX controls in `%WINDIR%\Downloaded Program Files` (`occache.dll`) |
| Feedback Hub Archive log files | `Feedback Hub Archive log files` | `%PROGRAMDATA%\Microsoft\Diagnosis\FeedbackArchive` |
| Temporary Internet Files | `Internet Cache Files` | WinINet cache (`ieframe.dll`) |
| Language Resource Files | `Language Pack` | unused language resources such as keyboards and speech inputs (`LanguagePackDiskCleanup.dll`) |
| Offline Web Pages | `Offline Pages Files` | Internet Explorer offline pages (`ieframe.dll`) |
| Old Chkdsk files | `Old ChkDsk Files` | `*.CHK` in `<drive>:\FOUND.000` to `FOUND.009` |
| Previous Windows installation(s) | `Previous Installations` | `Windows.old` |
| Recycle Bin | `Recycle Bin` | Recycle Bin |
| RetailDemo Offline Content | `RetailDemo Offline Content` | `%PROGRAMDATA%\Microsoft\Windows\RetailDemo` |
| Setup Log Files | `Setup Log Files` | `setup*.log`, `setup*.old`, `setuplog.txt`, `winnt32.log` in `%WINDIR%` |
| System error memory dump files | `System error memory dump files` | `*.dmp` in `%WINDIR%` (`MEMORY.DMP`) |
| System error minidump files | `System error minidump files` | `%WINDIR%\Minidump\*.dmp` |
| Temporary files | `Temporary Files` | files unused for 7 days in `%TEMP%`, `%WINDIR%\Temp`, `%WINDIR%\Logs`, `%WINDIR%\System32\LogFiles`, `%WINDIR%\SystemTemp`, `%LOCALAPPDATA%\Microsoft\Windows\TaskManager\LiveKernelDumps`, `%PROGRAMDATA%\Microsoft\WDF`, `%PROGRAMDATA%\Microsoft\Windows\HiveUpload` |
| Temporary Windows installation files | `Temporary Setup Files` | `$Windows.~BT` (`setupcln.dll`) |
| Temporary Sync Files | `Temporary Sync Files` | Windows Media Player Legacy sync files (`wmp.dll`) |
| Thumbnails | `Thumbnail Cache` | `thumbcache_*.db` (`thumbcache.dll`) |
| Windows Update Cleanup | `Update Cleanup` | superseded updates in component store (`scavengeui.dll`) |
| Files discarded by Windows upgrade | `Upgrade Discarded Files` | `$WINDOWS.~Q`, `$INPLACE.~TR`, `$Windows.~LS` |
| User file versions | `User file versions` | File historys local staging area (`fhcleanup.dll`) |
| Microsoft Defender Antivirus | `Windows Defender` | `%PROGRAMDATA%\Microsoft\Windows Defender\LocalCopy` and `Support` |
| Windows error reports and feedback diagnostics | `Windows Error Reporting Files` | runs `wermgr.exe -purgestores`, then `%PROGRAMDATA%\Microsoft\Windows\WER` |
| Windows ESD installation files | `Windows ESD installation files` | `ESD\Windows`, `$Windows.~WS`, `ESD\Download` |
| System recovery log files | `Windows Reset Log Files` | logs of earlier resets (`setupcln.dll`) |
| Windows upgrade log files | `Windows Upgrade Log Files` | `%WINDIR%\Panther` after an upgrade |
