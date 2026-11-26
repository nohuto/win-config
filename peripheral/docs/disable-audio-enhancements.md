# Disable Audio Enhancements

Audio enhancements are software based sound processing features that change or improve how playback or microphone audio sounds on a device. In general, they are used to improve clarity, balance volume, reduce noise, boost certain frequencies, or simulate spatial/surround effects, depending on the device and driver, but they can also cause audio issues etc., which is why you may want to disable them.

## Registry Values

The values below are related to `Exclusive Mode`/`Signal Enhancements`, see [property-sets](https://winsps-kb.readthedocs.io/en/latest/sources/property-sets/) for a list of more names.

The structure is `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\MMDevices\Audio\{Render\|Capture}\{Endpoint}`.

- `Render` = Playback
- `Capture` = Recording

| Value | Meaning | Data |
| --- | --- | --- |
| `\FxProperties\{1da5d803-d492-4edd-8c23-e0c0ffee7f0e},5` | Audio Enhancements / System Effects ([`PKEY_AudioEndpoint_Disable_SysFx`](https://learn.microsoft.com/en-us/windows/win32/coreaudio/pkey-audioendpoint-disable-sysfx)) - "*The PKEY_AudioEndpoint_Disable_SysFx property specifies whether system effects are enabled in the shared-mode stream that flows to or from the audio endpoint device. System effects are implemented as audio processing objects (APOs) that can be inserted into an audio stream. APOs are software modules that perform audio processing functions such as volume control and format conversion. Disabling the system effects for an endpoint device enables the associated stream to pass through the APOs unmodified.* | `1` = Off, `0` = On | 
| `\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},3` | Allow applications to take exclusive control (`Render_AudioEndpoint_Flag`) | `0` = Off, `1` = On | 
| `\Properties\{b3f8fa53-0004-438e-9003-51a46e139bfc},4` | Give exclusive mode applications priority (`Render_AudioEndpoint_Flag2`) | `0` = Off, `1` = On |
