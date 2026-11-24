# Disable Automatic Map Downloads

Disables automatic network traffic on the settings page and prevents automatic downloading or updating of map data, limiting location related data updates, the option also disables the `MapsBroker` service (offline maps in the 'Maps' app stop working).

`AllowOfflineMapsDownloadOverMeteredConnection`:

| Value | Description |
| ---- | ---- |
| `0` | Disabled, force disable auto update over metered connection |
| `1` | Enabled, force enable auto update over metered connection |
| `65535` (Default) | Not configured, users choice |

`EnableOfflineMapsAutoUpdate` (MDM side of `AutoDownloadAndUpdateMapData` ([Policy CSP Maps](https://learn.microsoft.com/en-us/windows/client-management/mdm/policy-csp-maps#enableofflinemapsautoupdate)), read in `CMapsOrchModel::GetAutoUpdatePolicy`, see [maps.c](https://github.com/nohuto/win-config/blob/main/privacy/assets/pseudocode/maps.c)):

| Value | Description |
| ---- | ---- |
| `0` | Disabled, force off auto update |
| `1` | Enabled, force on auto update |
| `65535` (Default) | Not configured, users choice |

## moshostcore Snippets

- `moshostcore` = Downloaded Maps Manager Core

```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"AutoUpdateEnabled", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetAutoUpdateEnabledSetting",
					   3025,
					   this);
return v5;
```
```c
v8 = 1; // Default
LOBYTE(a3) = 1;
v5 = 0;
MapsPersistedRegBoolean = RegUtils::GetMapsPersistedRegBoolean(this, L"UpdateOnlyOnWifi", a3, &v8);
if ( MapsPersistedRegBoolean >= 0 )
*a2 = v8 != 0;
else
return (unsigned int)ZTraceReportPropagation(
					   MapsPersistedRegBoolean,
					   "ServiceManager::GetDownloadOnlyOnWifiSetting",
					   3043,
					   this);
return v5;
```
```c
v6 = sub_180022E1C(L"System\\Maps\\Configuration", L"OfflineMaps");
if ( v6 < 0 )
{
  v7 = 3888LL;
  goto LABEL_4;
}
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off Automatic Download and Update of Map Data](https://noverse.dev/policies?p=WinMaps*TurnOffAutoUpdate) | `HKLM\Software\Policies\Microsoft\Windows\Maps` | `AutoDownloadAndUpdateMapData` |
| [Turn off unsolicited network traffic on the Offline Maps settings page](https://noverse.dev/policies?p=WinMaps*DisallowUntriggeredNetworkOnSettingsPage) | `HKLM\Software\Policies\Microsoft\Windows\Maps` | `AllowUntriggeredNetworkTrafficOnSettingsPage` |
