# Delivery Optimization Files

Delivery Optimization (DoSvc) stores update files under `%WINDIR%\SoftwareDistribution\DeliveryOptimization`, uses `%WINDIR%\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows\DeliveryOptimization` for cache metadata, and `%PROGRAMDATA%\Microsoft\Network\Downloader` for the BITS session data. The option stops DoSvc to delete the files, but won't start it as it's not recommended to have it enabled anyway.

Paths removed:
```c
%WINDIR%\SoftwareDistribution\DeliveryOptimization\*
%WINDIR%\ServiceProfiles\NetworkService\AppData\Local\Microsoft\Windows\DeliveryOptimization\*
%PROGRAMDATA%\Microsoft\Network\Downloader\*
```

