# Audio Ducking

> "*A communication device is used primarily for placing or receiving telephone calls on the computer. For a computer that has only one rendering device (speaker) and one capture device (microphone), these audio devices also act as the default communication devices.*"
>
> — Microsoft, [Using a Communication Device](https://learn.microsoft.com/en-us/windows/win32/coreaudio/using-the-communication-device)

> "*Consider a scenario where a user receives a phone call while listening to music on the computer. During the phone call, the user wants to reduce the volume level of the music while attending to the phone call, and resume the original volume after the phone call has ended. Depending on the options specified by the user in the Sounds control panel, the operating system automatically provides this functionality through ducking or stream attenuation—reduction in the intensity of an audio stream.*
>
> *The default attenuation experience depends on the user's preference, as specified in the control panel's Sound option. On the Communications tab, the user can choose an attenuation level (default value is 80%), mute all non-communication streams, or disable the default stream attenuation experience. The system allows new non-communication streams (except for new system sounds) to be opened during the communication session but the new streams are not automatically attenuated. When all of the communication streams are closed, the system ends the communication session and restores the volume of the streams that were attenuated during the communication session.*"
>
> — Microsoft, [Default Ducking Experience](https://learn.microsoft.com/en-us/windows/win32/coreaudio/stream-attenuation)

## Registry Value

See '[Audio Values](https://noverse.dev/docs/win-config/peripheral/audio-values/)' for other related values.

```c
"HKCU\\Software\\Microsoft\\Multimedia\\Audio";
  // LoadUserSettings
  "UserDuckingPreference" = 1; // REG_DWORD, range 0-3, >3 = 1
                               // 0 = -96 dB
                               // 1 = -18 dB
                               // 2 = -6 dB
                               // 3 = 0 dB
```

```c
float __fastcall CDuckingManager::GetdBFromUserPreference(int a1)
{
  int v1; // ecx

  if ( !a1 )
    return FLOAT_N96_0; // 0
  v1 = a1 - 1;
  if ( !v1 )
    return FLOAT_N18_0; // 1, should be FLOAT_N14_0
  if ( v1 == 1 )
    return FLOAT_N6_0; // 2
  return 0.0; // 3
}
```

Fun fact: the `Reduce the volume of other sounds by 80%` audio ducking option isn't accurate at all (it's ~87%).

- [LoadUserSettings](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/AudioSrvPolicyManager/-LoadUserSettings@@YAXPEAVTSSession@@PEAUHKEY__@@@Z.c)

### MMSYS Capture

Capture of `control mmsys.cpl,,3`.

```c
// Mute all other sounds
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 0

// Reduce the volume of other sounds by 80% (default)
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 1

// Reduce the volume of other sounds by 50%
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 2

// Do nothing
HKCU\Software\Microsoft\Multimedia\Audio\UserDuckingPreference	Type: REG_DWORD, Length: 4, Data: 3
```

