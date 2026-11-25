# Disable Wi-Fi Sense

> "*Wi-Fi Sense automatically connects devices to known hotspots and to the wireless networks the person’s contacts have shared with them.*"
>
> — Microsoft, [Manage connections: Wi-Fi Sense](https://learn.microsoft.com/en-us/windows/privacy/manage-connections-from-windows-operating-system-components-to-microsoft-services#23-wi-fi-sense)

Beginning with W10, version 1803, Wi-Fi Sense is no longer available. W10 22H2 & W11 still read `AutoConnectAllowedOEM`, but nothing uses the stored value:

```c
// FeatureManager::QueryCurrentOemAutoConnectEnabledRegKey (23H2)

  GetPersistentRegPath(9LL, L"config", &v3, SubKey);
  return RegGetValueW(HKEY_LOCAL_MACHINE, SubKey, L"AutoConnectAllowedOEM", 0x10u, 0LL, &pvData, &pcbData)
      || pcbData != 4
      || pvData != 0; // absent/nonzero = 1
```

```c
// FeatureManager::GetFeatureListInternal (23H2)

  *((_DWORD *)a3 + 7) = (a2 >> 7) & 1;
  *((_DWORD *)a3 + 8) = (a2 >> 8) & 1;
  *(_DWORD *)a3 = 2; // the other entries are constants, no AutoConnectAllowedOEM input
  *((_DWORD *)a3 + 1) = 2;
  *((_DWORD *)a3 + 2) = 2;
  *((_DWORD *)a3 + 3) = 2;
  *((_DWORD *)a3 + 4) = 2;
  *((_DWORD *)a3 + 5) = 2;
  *((_DWORD *)a3 + 6) = 2;
  *((_DWORD *)a3 + 10) = 2;
  *((_DWORD *)a3 + 9) = 2;
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Allow Windows to automatically connect to suggested open hotspots, to networks shared by contacts, and to hotspots offering paid services](https://noverse.dev/policies?p=wlansvc*WiFiSense) | `HKLM\Software\Microsoft\wcmsvc\wifinetworkmanager\config` | `AutoConnectAllowedOEM` |
