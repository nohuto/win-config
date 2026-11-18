# Sound Mode

## Spatial Audio

> "*Microsoft Spatial Sound is Microsoft’s platform-level solution for spatial sound support on Xbox, Windows and HoloLens 2, enabling both surround and elevation (above or below the listener) audio cues. Spatial sound can be leveraged by Windows desktop (Win32) apps as well as Universal Windows Platform (UWP) apps on supported platforms. The spatial sound APIs allow developers to create audio objects that emit audio from positions in 3D space.*"
>
> — Microsoft, [Spatial Sound for app developers for Windows, Xbox, and Hololens 2](https://learn.microsoft.com/en-us/windows/win32/coreaudio/spatial-sound)


![](https://github.com/nohuto/win-config/blob/main/peripheral/images/spatial.jpeg?raw=true)

### Registry Values

See '[Audio Values](https://noverse.dev/docs/win-config/peripheral/audio-values/)' for other related values.

```c
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio";
  // BlockSpatialAudioRegistryGates
  "DisableSpatialAudioGlobal" = 0; // REG_DWORD (bool)
  "DisableSpatialAudioPerEndpoint" = 1; // REG_DWORD (bool), nonzero = PKEY_Endpoint_SpatialNotAllowed
  "DisableSpatialAudioVssFeature" = 0; // REG_DWORD (bool)
  "SpatialAudioHrtfOnByDefault" = 0; // REG_DWORD (bool)

  // IsSpatialComboEndpointDeterminationDisabled
  "DisableSpatialOnComboEndpoints" = 1; // REG_DWORD (bool)

"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Audio\\Policy\\Spatial";
  // AtmosCheck::GetSpatialAudioLicenseGracePeriodInMs
  "SpatialAudioLicenseCheckStartDelay" = 5; // REG_DWORD, range 1-900000 ms, 0/>900000 = 5 ms

  // IsMultiUserSKU
  "SpatialAudioLicenseCheckRequiresUserContext" = 0; // REG_DWORD (bool)
```

Disabling spatial sound via these values would gray out the option in the device properites, but Windows itself doesn't disable/enable it via them.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/spatialsystemsettings.png?raw=true)

- [BlockSpatialAudioRegistryGates](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/audiosrv/BlockSpatialAudioRegistryGates.c)
- [IsSpatialComboEndpointDeterminationDisabled](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/audiosrv/IsSpatialComboEndpointDeterminationDisabled.c)
- [GetSpatialAudioLicenseGracePeriodInMs](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/audiosrv/-GetSpatialAudioLicenseGracePeriodInMs@AtmosCheck@@CAHXZ.c)
- [IsMultiUserSKU](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/audiosrv/-IsMultiUserSKU@@YA_NXZ.c)

## Mono/Stereo Audio

Mono combines left and right audio channels into one, stereo uses two channels.

![](https://github.com/nohuto/win-config/blob/main/peripheral/images/mono-stereo.jpg?raw=true)

### SystemSettings Capture

```c
// System > Sound : Mono audio

// Enabled
HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 1

// Disabled
HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 0
```

