# Game Mode

Game Mode is a RM (Resource Manager) feature for a foreground process that Windows identifies as a game through `expandedResources` (or GCS data). Note that everything below is based on pseudocode (from 23H2, things might've changed in newer builds, see [diff](https://noverse.dev/diff?kind=pseudocode)) and interpretations, this isn't official documentation just a personal attempt to document how Game Mode works, mistakes may exist and feel free to correct me. I don't claim that anything below is correct nor complete, that's just how I understood the sequence of Game Mode initialization + (un)registration. I've tried to link all functions that I used, for anyone who wants to take a look for themselves.

It can apply CPU set policy, GPU scheduler/budget policy, optional process priority, optional Game Mode power profile notification, global Game Mode active state, optional expanded resource extension notification. The global state is updated through `WNF_RM_GAME_MODE_ACTIVE` (`RM` prefix in `WNF_RM_GAME_MODE_ACTIVE` = '*Game Mode Resource Manager*').

This means that we can check the game mode state via `WNF_RM_GAME_MODE_ACTIVE`. `PsmServiceExtHost.dll` writes this state from [`RmpSystemPublishGlobalGameModeState`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemPublishGlobalGameModeState@@YAXK@Z.c). The public [`HasExpandedResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/gamemode/HasExpandedResources.c) API reads the same state and returns true only when the value equals the current PID.

Note that you don't have to restart your PC/game when going from disabled to enabled (since it registers the PID when game gets in FG), but you need to restart the game when going from enabled to disabled (since the PID stays registered, which is why restarting the game is enough as that causes the PID to change).

```c
// RmpSystemPublishGlobalGameModeState
v3 = a1; // active Game Mode PID or 0 when no process is active (GameModeActivePid=0 in gm_effects)
if ( (int)RtlPublishWnfStateData(WNF_RM_GAME_MODE_ACTIVE, 0LL, &v3, 4LL, 0LL) < 0
```

```c
// HasExpandedResources
if ( (int)NtQueryWnfStateData(&WNF_RM_GAME_MODE_ACTIVE, 0LL, 0LL, &v6, &v4, &v5) >= 0 )
{
  LOBYTE(v1) = GetCurrentProcessId() == v4; // true only for the active Game Mode PID
  *hasExpandedResources = v1;
}
```

## gm_effects

I've created [`gm_effects.exe`](https://github.com/nohuto/utils/releases/download/0.1.0/gm_effects.exe), which reads the current foreground PID, active Game Mode PID, process default CPU sets (and CPU set IDs), and the Game Mode power profile WNF low value. You can either use the prebuild binary, or build it yourself from [source](https://github.com/nohuto/utils/tree/main/gm_effects):

```powershell
cmake -S . -B build
cmake --build build --config Release

.\build\Release\gm_effects.exe
```

If you want it to loop faster/slower, change `Sleep(1000)`, it also support a `--pid` argument which lets you track a single PID instead of the current foreground process.

Microsoft also documents behavior that I didn't find in the RM functions, so I guess it's handled somewhere else, such as "Game Mode can suppress Windows Update driver installs and Windows Update restart notifications while a game is running".

## Registry Values

The `AllowAutoGameMode` value gets read by [`EvaluateAppForGameMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateAppForGameMode@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUBroadcastDVRActive.c), but isn't present in the default LGPE policy list ([policies.json](https://raw.githubusercontent.com/nohuto/admx-parser/refs/heads/main/assets/policies.json)). Other registry values are used in [`GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c) and [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c).

```c
"HKCU\\Software\\Microsoft\\GameBar";
    "AutoGameModeEnabled" = 1; // missing/nonzero allows registration
    "GpuGameMemoryBudgetPercentage" = 50; // fallback game GPU memory budget percent
    "GpuDwmMemoryBudgetPercentage" = 30; // fallback system compositor GPU memory budget percent
    "GpuYieldPercentage" = 2; // fallback GPU yield percent, range 2-10
    "DisallowSystemAllowedCpuSets" // nonzero disallows system allowed CPU set policy

"HKLM\\Software\\Policies\\Microsoft\\Windows\\GameDVR";
    "AllowAutoGameMode" = 1; // missing/nonzero allows registration, adding this with a value of 0 would hide the Game Mode part in system settings
```

## Game Mode Process

Obviously, this doesn't include every single part, rather I've tried to keep it simple and focus on the main parts.

### Shell Entry

It starts in `twinui.pcshell.dll`, [`BroadcastDVRComponent::EvaluateAppForGameMode`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateAppForGameMode@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUBroadcastDVRActive.c) is called if application change, application view change, Game Mode enable change tasks happen.

The application change task calls `EvaluateAppForGameMode` after it has updated the active app information for the changed application view:

```c
// BroadcastDVRComponent::ApplicationChangedTask
BroadcastDVRComponent::EvaluateAppForGameMode((BroadcastDVRComponent *)a1, v7, v13); // v7 = application view, v13 = active app info
```

The application view change task uses the same function when the changed view is already known to the BroadcastDVR component:

```c
// BroadcastDVRComponent::OnApplicationViewChangedGameMode
BroadcastDVRComponent::EvaluateAppForGameMode((BroadcastDVRComponent *)a1, a2, (HWND *)v8); // a2 = application view, v8 = active app info
```

When the user enables Game Mode for the active window, [`OnGameModeEnableChangeTask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-OnGameModeEnableChangeTask@BroadcastDVRComponent@@AEAAXPEAUHWND__@@_N@Z.c) refreshes the GCS (game config store) state and then calls the same Game Mode check:

```c
// BroadcastDVRComponent::OnGameModeEnableChangeTask
BroadcastDVRComponent::EvaluateAppForGameMode(this, v6, (HWND *)v7); // v6 = application view, v7 = active app info
```

### Get Values

`EvaluateAppForGameMode` first gets the two values, a missing value passes, `0` blocks registration. Means if you set one of these values to `0`, all steps below won't run.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode

v29 = 0;
if ( (SHRegGetDWORD(
        HKEY_LOCAL_MACHINE,
        L"Software\\Policies\\Microsoft\\Windows\\GameDVR",
        L"AllowAutoGameMode",
        &v29) < 0
    || v29)
&& (SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"AutoGameModeEnabled", &v29) < 0 || v29) )
```

Note that this is a AND logic (`&&`) so both must either be `1` or not present.

### Check expandedResources

`EvaluateAppForGameMode` first checks whether the active view has the `expandedResources` capability through [`BroadcastDVRComponent::IsExpandedResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsExpandedResources@BroadcastDVRComponent@@AEAAJPEAUIApplicationView@@PEA_N@Z.c) (this is separate from the public [`HasExpandedResources`](https://learn.microsoft.com/en-us/windows/win32/api/expandedresources/nf-expandedresources-hasexpandedresources) API in `gamemode.dll`).

If `expandedResources` is present, it continues with Game Mode reason `5`. If it's not present it calls [`IsGameModeGame`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsGameModeGame@BroadcastDVRComponent@@AEAA_NPEAUGameConfigInfo@@PEAW4GameModeReason@@@Z.c), which uses GCS data filled by [`EvaluateIfViewIsGame`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-EvaluateIfViewIsGame@BroadcastDVRComponent@@AEAAXPEAUIApplicationView@@PEAUGameConfigInfo@@PEA_.c). If `IsGameModeGame` returns false, the function exits before process registration, so all steps below won't run again.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
IsExpandedResources = BroadcastDVRComponent::IsExpandedResources(v6, a2, &v27); // v27 = has expandedResources
v12 = v27 ? 5 : 0; // reason 5
if ( !v27 ) // fallback to GCS
{
  if ( !BroadcastDVRComponent::IsGameModeGame(v11, v7, (enum GameModeReason *)&v30) )
    return; // not a Game Mode game
  v12 = (unsigned int)v30; // Game Mode reason returned by IsGameModeGame
}
```

### Resolve the Process

It converts the active HWND (window handle) to a PID with [`GetWindowThreadProcessId`](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getwindowthreadprocessid). If the same PID is already registered, it doesn't register the primary process again.

For a new PID, it opens the process with [`PROCESS_QUERY_LIMITED_INFORMATION`](https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights) ("*Required to retrieve certain information about a process (see [GetExitCodeProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess), [GetPriorityClass](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getpriorityclass), [IsProcessInJob](https://learn.microsoft.com/en-us/windows/win32/api/jobapi/nf-jobapi-isprocessinjob), [QueryFullProcessImageName](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-queryfullprocessimagenamea))*"). If the active view is a WinRT (Windows Runtime) application, it reads the process image name and skips `applicationframehost.exe` since that's the UWP frame host.

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
if ( v8 )
  v9 = v8; // v9 = HWND
GetWindowThreadProcessId(v9, &v28); // v28 = active process ID
if ( v28 )
{
  if ( v28 == *((_DWORD *)this + 114) ) // already registered primary PID
  {
    BroadcastDVRComponent::GetNonServiceProcessListAndIds(this, &v33);
    BroadcastDVRComponent::ApplyGameRelatedForGameModeProcess((__int64)this, v28, &v33);
    BroadcastDVRComponent::TelemetryLogProcessesLaunchedAfterGame(v15, &v35);
    return;
  }
}
```

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
hProcess = 0LL;
v18 = OpenProcess(0x1000u, 0, v28); // 0x1000 = PROCESS_QUERY_LIMITED_INFORMATION, v28 = PID
wil::details::unique_storage<wil::details::handle_null_resource_policy<int (*)(void *),&int CloseHandle(void *)>>::reset(&hProcess, v18);
v20 = (char *)hProcess; // process handle used below
```

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
if ( a2 )
{
  if ( (int)Microsoft::WRL::ComPtr<IApplicationView>::As<IWinRTApplicationView>(&v30, (__int64)&v31) >= 0 )
  {
    if ( K32GetModuleFileNameExW(v20, 0LL, Filename, 0x104u) )
    {
      FileNameW = PathFindFileNameW(Filename);
      if ( CompareStringOrdinal(FileNameW, -1, L"applicationframehost.exe", -1, 1) == 2 )
        goto LABEL_28; // skip the UWP frame host process
    }
  }
}
```

### Build the Request

It initializes a RM request, asks the service for the current request limits, then adds GCS and registry values in [`GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c).

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
v35 = 0LL;
v36 = 0LL;
v37 = 0LL;
RmGameModeInitializeResourceRequest(&v35); // v35 = resource request buffer
LargestValidResourceRequest = RmGameModeGetLargestValidResourceRequest(&v35);
if ( LargestValidResourceRequest < 0 )
{
  wil::details::in1diag3::_Log_Hr(
    retaddr,
    (void *)0x825,
    (int)"pcshell\\twinui\\broadcastdvrcomponent\\lib\\broadcastdvrprovider.cpp",
    (const char *)(LargestValidResourceRequest | 0x10000000u));
  goto LABEL_28;
}
BroadcastDVRComponent::GetGameModeRequest(this, v12, v7, &v35);
v23 = RmGameModeRegisterProcess(v20, &v35, 0LL);
```

In `rmclient.dll`, [`RmGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/rmclient/RmGameModeRegisterProcess.c) sends the process handle and Game Mode request to the RM service through RPC.

```c
// RmGameModeRegisterProcess
if ( (int)sub_180005FC0(&unk_180022A10, Binding) >= 0 )
{
  v6 = 1;
  v10 = a3;
  v8.Pointer = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&stru_180020F80, 0, 0LL, Binding[0], a1, a2, v10).Pointer;
  Pointer = (unsigned int)v8.Pointer;
  Binding[1] = v8.Pointer;
  if ( SLODWORD(v8.Simple) >= 0 )
    Pointer = 0;
}
```

### Set Defaults

[`RmGameModeInitializeResourceRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/rmclient/RmGameModeInitializeResourceRequest.c) writes the default values into the request.

```c
// RmGameModeInitializeResourceRequest
__int64 __fastcall RmGameModeInitializeResourceRequest(__int64 a1)
{
  __int64 result; // rax

  result = 0LL;
  *(_OWORD *)a1 = 0LL;
  *(_OWORD *)(a1 + 16) = 0LL;
  *(_QWORD *)(a1 + 32) = 0LL;
  *(_DWORD *)a1 = 6; // request version
  *(_DWORD *)(a1 + 16) = 10; // GPU yield percentage
  *(_DWORD *)(a1 + 20) = 50; // game GPU memory budget
  *(_DWORD *)(a1 + 24) = 30; // system compositor GPU memory budget
  return result;
}
```

### Validate in the Service

[`RmSrvGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmSrvGameModeRegisterProcess@@YAJPEAU_RM_SERVICE_GLOBALS@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c) receives the registration request inside the service, it validates the request in [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c), then calls [`RmpGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRegisterProcess@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c).

- Request version must be `6`
- GPU yield must be `2-10`
- Game and system compositor memory percentages must total `<= 100`
- Priority class may be unset or one of `2`, `3`, `6`

```c
// RmSrvGameModeRegisterProcess
if ( a4 )
{
  v8 = -1073741583;
}
else if ( RmpGameModeIsResourceRequestValid(v4, a3) ) // a3 = Game Mode request
{
  v8 = RmpGameModeRegisterProcess((struct _RM_SERVICE_GLOBALS *)((char *)v4 + 2096), a2, a3); // a2 = process handle
  if ( v8 >= 0 )
    v8 = 0;
}
else
{
  v8 = -1073741584; // invalid request
}
```

The validator has two parts, the first part accepts a default request only when the CPU allocation fields are empty and the graphics values still match the base defaults, the second part checks the normal limits for CPU count, CPU set mask, priority class, GPU yield, and GPU memory budgets.

```c
// RmpGameModeIsResourceRequestValid
if ( *(_DWORD *)a2 == 6 ) // request version
{
  v6 = *((_DWORD *)a2 + 8) & 5; // selects which request form is being validated
  if ( v6 != 4
    && (v6 != 1
     || !*((_DWORD *)a2 + 1) // cannot carry an CPU count
     && !*((_QWORD *)a2 + 1) // cannot carry an CPU set mask
     && *((_DWORD *)a2 + 4) == 10 // GPU yield must stay at default
     && *((_DWORD *)a2 + 5) == 50 // game GPU memory budget must stay at default
     && *((_DWORD *)a2 + 6) == 30 // system compositor GPU memory budget must stay at default
     && (*((_BYTE *)a2 + 32) & 8) == 0) ) // graphics priority cant be set
  {
    v7 = RtlNumberOfSetBitsUlongPtr(*((_QWORD *)a2 + 1), a2, a3, a4); // number of CPUs in the CPU set mask
    v8 = *((_DWORD *)a2 + 1); // requested exclusive CPU count
    if ( v8 >= v7
      && v8 <= 0x40
      && RmpCpuSetManagerIsGameModeRequestSatisfiable(
           (struct _RM_SERVICE_GLOBALS *)((char *)a1 + 680),
           (*((_DWORD *)a2 + 7) & 0x40) != 0, // CPU count increase
           v8,
           *((_QWORD *)a2 + 1)) // CPU set mask
      && (!*((_BYTE *)a2 + 36) || *((_BYTE *)a2 + 36) == 2 || *((_BYTE *)a2 + 36) == 3 || *((_BYTE *)a2 + 36) == 6) // priority class
      && (unsigned int)(*((_DWORD *)a2 + 4) - 2) <= 8 // GPU yield range = 2-10
      && (unsigned int)(*((_DWORD *)a2 + 5) + *((_DWORD *)a2 + 6)) <= 0x64 // GPU memory budgets = total 100 or less
      && (*((_BYTE *)a2 + 28) & 0x18) != 0x18 )
    {
      return 1;
    }
  }
}
```

### Create Process State

After validation [`RmpGameModeRegisterProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRegisterProcess@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_RESOURCE_REQUES.c) turns the request into a service managed process state. The request is copied by [`RmpGameModeInitializeRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeInitializeRecipientProcess@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RESOURCE.c), then [`RmpGameModeFindProcessOrCompleteInsertion`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeFindProcessOrCompleteInsertion@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAXPEAU_RM_GAME_MODE_.c) checks whether that PID is already known to the service.

If it's a new PID, [`RmpGameModeAllocateObjectsForRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAllocateObjectsForRecipientProcess@@YAJPEAU_RM_GAME_MODE_RECIPIENT_PROCESS@@PEAX@Z.c) prepares the service state for it, it creates the process exit wait object, opens its own process handle and stores the PID. [`RmpGameModeInsertRecipientProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeInsertRecipientProcess@@YAXPEAU_RM_GAME_MODE_RECIPIENT_PROCESS@@@Z.c) then adds that process state to the Game Mode context, starts the exit wait, and queues the policy worker.

### Apply Resource Policies

[`RmpGameModePolicyWorker`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModePolicyWorker@@YAXPEAU_TP_CALLBACK_INSTANCE@@PEAXPEAU_TP_WORK@@@Z.c) applies Game Mode policy. For newly registered processes it can acquire global resources (`RmpGameModeAcquireGlobalResources`), apply per process policies (`RmpGameModeApplyNewRecipientPolicies`), apply global policies (`RmpGameModeApplyGlobalPolicies`), release unused global resources (`RmpGameModeReleaseUnusedGlobalResources`).

```c
// RmpGameModePolicyWorker
if ( v14 )
  RmpGameModeNotifyExtensionRecipientsPresent((struct _RM_GAME_MODE_CONTEXT *)a2, v14 != 0);
if ( v47.Flink != &v47 ) // v47 = list of processes that need policy work
{
  RmpGameModeAcquireGlobalResources((struct _RM_GAME_MODE_CONTEXT *)a2, &v47);
  RmpGameModeApplyNewRecipientPolicies((struct _RM_GAME_MODE_CONTEXT *)a2, &v47);
  RmpGameModeApplyGlobalPolicies((struct _RM_GAME_MODE_CONTEXT *)a2);
  RmpGameModeReleaseUnusedGlobalResources((struct _RM_GAME_MODE_CONTEXT *)a2);
}
```

```c
// RmpGameModeApplyNewRecipientPolicies
while ( a2->Flink != a2 ) // a2 = list of processes waiting for policy application
{
  v4 = CempListRemoveHeadAndClear(a2); // remove one process from the work list
  RmpGameModeAcquireAndApplyRecipientResources(a1, (struct _RM_GAME_MODE_RECIPIENT_PROCESS *)(v4 - 11)); // run the policy table for that process
  *((_BYTE *)v4 + 83) &= ~1u;
  v5 = (char *)a1 + 16 * *((int *)v4 + 4) + 88;
```

[`RmpGameModeAcquireAndApplyRecipientResources`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAcquireAndApplyRecipientResources@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_R.c) uses five resource policy entries and calls the apply function for each active entry. 

More detail about them in [CPU set policy](https://noverse.dev/docs/win-config/system/game-mode/#cpu-sets), [GPU policy](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget), [power profile state](https://noverse.dev/docs/win-config/system/game-mode/#game-mode-power-profile-wnf-state), [process priority](https://noverse.dev/docs/win-config/system/game-mode/#process-priority-class), [extension state](https://noverse.dev/docs/win-config/system/game-mode/#expanded-resource-extension-notification).

```c
// RmpGameModeAcquireAndApplyRecipientResources
v2 = 0;
v3 = off_1800B40C0; // Game Mode resource policies
for ( i = 0; i < 5; ++i )
{
  v7 = 1 << i; // one bit per policy entry
  if ( *((_BYTE *)v3 + 33) )
    goto LABEL_11;
  if ( !*v3 )
    goto LABEL_10;
  if ( *((_BYTE *)v3 + 32) )
  {
    if ( (v7 & *((_DWORD *)a1 + 32)) == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  v8 = (*v3)(a1, a2); // apply one policy entry to process
  if ( v8 >= 0 && v8 != 255 )
  {
    *((_DWORD *)a2 + 40) |= v7; // remember that policy was applied
LABEL_10:
    v2 |= v7; // remember that policy was handled in this pass
  }
LABEL_11:
  v3 += 5;
}
```

### Register Related Processes

After primary registration, `twinui.pcshell.dll` stores the registered PID, gets the current non service process list and calls [`ApplyGameRelatedForGameModeProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForGameModeProcess@BroadcastDVRComponent@@AEAAXKAEBV-$vector@U-$pair@KVString@I.c). It asks the game manager for related process names, compares process image names, and calls [`ApplyGameRelatedForRelatedProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForRelatedProcess@BroadcastDVRComponent@@AEAAXKGK@Z.c) for matches.

See more detail in [Related Processes](https://noverse.dev/docs/win-config/system/game-mode/#related-processes).

```c
// BroadcastDVRComponent::EvaluateAppForGameMode
*((_DWORD *)this + 114) = v28; // remember primary PID
v33 = 0LL;
v34 = 0LL;
BroadcastDVRComponent::GetNonServiceProcessListAndIds(this, &v33);
BroadcastDVRComponent::ApplyGameRelatedForGameModeProcess((__int64)this, v28, &v33); // register matching related processes
std::vector<Windows::Internal::String>::clear((char *)this + 352);
BroadcastDVRComponent::GetSortedUniqueProcessList(v25, &v33, (char *)this + 352);
BroadcastDVRComponent::TelemetryLogProcessesLaunchedWithGame(v26, (char *)this + 352);
```

### Pair Auxiliary Processes

Related processes are paired with the primary process through `RmGameModeRegisterPairedAuxiliaryProcess`, they're matched by process image name against the related process list returned by the GCS/game manager.

### End by Toggle Disable

When Game Mode is disabled for the active HWND/PID, [`OnGameModeEnableChangeTask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-OnGameModeEnableChangeTask@BroadcastDVRComponent@@AEAAXPEAUHWND__@@_N@Z.c) calls `RmGameModeDisableForRegisteredProcess`, then `RmGameModeUnregisterProcess`.

```c
// BroadcastDVRComponent::OnGameModeEnableChangeTask
v14 = RmGameModeDisableForRegisteredProcess(pv); // disable Game Mode policy
if ( v14 < 0 )
  goto LABEL_26;
v14 = RmGameModeUnregisterProcess(v13); // remove process
```

### End by Process Exit or Focus Change

The service also watches process lifetime with a threadpool wait. When the process terminates, paired auxiliary processes are cleared and the process is removed from Game Mode service state ([`RmpGameModeRecipientProcessTerminationCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeRecipientProcessTerminationCallback@@YAXPEAU_TP_CALLBACK_INSTANCE@@PEAXPEAU_TP_WAIT@.c)). Input focus changes queue the same policy worker so the active Game Mode state can move to another registered primary process ([`RmpSystemNotificationInputFocusChangeCallback`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemNotificationInputFocusChangeCallback@@YAJU_WNF_STATE_NAME@@KPEAU_WNF_TYPE_ID@@PEAXPEBX.c)).

This can be validated using [`gm_effects`](https://noverse.dev/docs/win-config/system/game-mode/#gm_effects) with the `--pid` argument, so you enable Game Mode, start the game, use `--pid` with the PID of the game, move the game to FG/BG. By doing so you'll see that the state changes.

```ini
; not in FG
Timestamp=20:47:10.665
FGPid=3996
GameModeActivePid=0
PowerProfileLowValue=1
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

; in FG
Timestamp=20:47:11.668
FGPid=9968
GameModeActivePid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
PowerProfileLowValue=3
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

Timestamp=20:47:12.670
FGPid=9968
GameModeActivePid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
PowerProfileLowValue=3
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0

; not in FG
Timestamp=20:47:13.685
FGPid=3372
GameModeActivePid=0
PowerProfileLowValue=1
TargetPid=9968
ProcessImage=Overwatch.exe
ProcessPath=C:\Program Files (x86)\Steam\steamapps\common\Overwatch\Overwatch.exe
DefaultCpuSetCount=0
```

## Effect Details

### Process Priority Class

Game Mode can temporarily change a registered process priority class if the request priority byte is nonzero (`2`/`6`/`3`, see below).

The request byte is the native `ProcessPriorityClass` value used by `NtSetInformationProcess`.

> "*Each thread has a base priority that is a function of its process priority class and its relative thread priority.*"
>
> "*Scheduling decisions are made based on the current priority.*"
>
> — Microsoft, [Windows Internals E7, P1: Chapter 4, Threads](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

That means a process priority class isn't the final scheduling value by itself. It sets the base priority that the process threads start from, the scheduler then uses each thread's current priority, which can include wait completion boosts, GUI boosts, MMCSS boosts, etc.

| Request byte | Public class | Thread base |
| --- | --- | --- |
| `0` | - | - |
| `2` | `NORMAL_PRIORITY_CLASS` | `8` |
| `6` | `ABOVE_NORMAL_PRIORITY_CLASS` | `10` |
| `3` | `HIGH_PRIORITY_CLASS` | `13` |

The accepted classes stay in the dynamic priority range, they obviously don't enter the real time range.

For the primary game process, [`BroadcastDVRComponent::GetGameModeRequest`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-GetGameModeRequest@BroadcastDVRComponent@@AEAAXW4GameModeReason@@PEAUGameConfigInfo@@PEAU_RM_GA.c) sets priority byte `2`. That means the primary game process is set to normal process priority class by Game Mode unless another component changes it later.

Example with a game that sets itself to real time (there're probably any game devs who do that without thinking about the impact) priority before Game Mode registers it:

1. The game starts as `REALTIME_PRIORITY_CLASS`
2. Game Mode registers the primary game process
3. The service saves the old priority class
4. The service writes `NORMAL_PRIORITY_CLASS`
5. When Game Mode is removed, the service can restore the saved old class

```c
// BroadcastDVRComponent::GetGameModeRequest
*(_BYTE *)(a4 + 36) = 2; // primary game request priority class
```

#### FG Boost with Game Mode

See '[PsPrioritySeparation (`1:0`)](https://noverse.dev/docs/win-config/system/priority-separation/#pspriorityseparation-10)' for more details on the FG process priority boosting.

You can test it by following the '[Watching the FG Priority Boost](https://noverse.dev/docs/win-config/system/priority-separation/#watching-the-fg-priority-boost)' guide while using the main game thread instead of the first CPUSTRES thread, get the instance name of a TID via e,g,:

```powershell
$TID = # add TID
Get-CimInstance Win32_PerfRawData_PerfProc_Thread | Where-Object { $_.IDThread -eq $TID } | Select-Object Name #, IDProcess, IDThread
```

> "*Whenever a thread in the foreground process completes a wait operation on a kernel object, the kernel boosts its current (not base) priority by the current value of PsPrioritySeparation.*"
>
> "*The windowing system is responsible for determining which process is considered to be in the foreground.*"
>
> — Microsoft, [Windows Internals E7, P1: Chapter 4, Threads](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

##### 23H2 (Game)

I've done it using Overwatch, both times I switched the state between FG/BG:

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-game.png?raw=true)

##### 23H2 (Other app)

Means that the missing FG boost only happens for processes that register with the game mode.

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-app-off.png?raw=true)
![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-23H2-app-on.png?raw=true)

##### 25H2

The issue doesn't seem to appear anymore on 25H2:

![](https://github.com/nohuto/win-config/blob/main/system/images/gamemode-25H2.png?raw=true)

#### Related Processes

[`ApplyGameRelatedForGameModeProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForGameModeProcess@BroadcastDVRComponent@@AEAAXKAEBV-$vector@U-$pair@KVString@I.c) compares running process image names against the related process list returned by the GCS/game manager. For matches, [`ApplyGameRelatedForRelatedProcess`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-ApplyGameRelatedForRelatedProcess@BroadcastDVRComponent@@AEAAXKGK@Z.c) builds the related process request. 

Related processes can get the normal, above normal, or high process priority class.

```c
// BroadcastDVRComponent::ApplyGameRelatedForRelatedProcess
if ( (a3 & 4) != 0 )
{
  BYTE4(v20) = 6; // above normal priority
}
else
{
  v14 = 2; // default normal priority
  if ( (a3 & 8) != 0 )
    v14 = 3; // high priority
  BYTE4(v20) = v14;
}
```

### CPU Sets

Game Mode can request CPU set allocation and apply CPU set restrictions and defaults to the registered process. A CPU set ID usually means one logical processor, and a process or thread can be assigned a list of CPU set IDs. Game Mode uses this to give the game a preferred or limited processor selection while moving selected system activity away from those CPU sets.

> "*Game mode tries to kind of steer away the processors from your game so the system itself and all the kernel threads and stuff like that are not going to use some processors, so your game can use those processors exclusively.*"
>
> — Pavel Yosifovich, [Windows Internals](https://youtu.be/h6BXMcRqYhA?t=3251)

> "*You've seen how affinity (sometimes referred to as hard affinity) can limit threads to certain processors, which is always honored by the scheduler. The ideal processor mechanism tries to run threads on their ideal processors (sometimes referred to as soft affinity), generally expecting to have the thread's state be part of the processor's cache. The ideal processor may or may not be used, and it does not prevent the thread from being scheduled on other processors. Both these mechanisms don't work on system-related activity, such as system threads activity. Also, there is no easy way to set hard affinity to all processes on a system in one stroke. Even walking the process would not work. System processes are generally protected from external affinity changes because they require the PROCESS_SET_INFORMATION access right, which is not granted for protected processes.*
> *Windows 10 and Server 2016 introduce a mechanism called CPU sets. These are a form of affinity that you can set for use by the system as a whole (including system threads activity), processes, and even individual threads. For example, a low-latency audio application may want to use a processor exclusively while the rest of the system is diverted to use other processors. CPU sets provide a way to achieve that.*
> *The documented user mode API is somewhat limited at the time of this writing. [GetSystemCpuSetInformation](https://learn.microsoft.com/en-us/windows/win32/procthread/getsystemcpusetinformation) returns an array of [SYSTEM_CPU_SET_INFORMATION](https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-system_cpu_set_information) that contains data for each CPU set. In the current implementation, a CPU set is equivalent to a single CPU. This means the returned array's length is the number of logical processors on the system. Each CPU set is identified by its ID, which is arbitrarily selected to be 256 (0x100) plus the CPU index (0, 1, ...). These IDs are the ones that must be passed to [SetProcessDefaultCpuSets](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessdefaultcpusets) and [SetThreadSelectedCpuSets](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadselectedcpusets) functions to set default CPU sets for a process and a CPU set for a specific thread, respectively. An example for setting thread CPU set would be for an "important" thread that should not be interrupted if possible. This thread could have a CPU set that contains one CPU, while setting the default process CPU set to include all other CPUs. One missing function in the Windows API is the ability to reduce the system CPU set. This can be achieved by a call to the [NtSetSystemInformation](https://learn.microsoft.com/en-us/windows/win32/sysinfo/ntsetsysteminformation) system call. For this to succeed, the caller must have SeIncreaseBasePriorityPrivilege.*
>
> — Microsoft, [Windows Internals E7, P1: 'Chapter 4, Multiprocessor systems'](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P1.pdf)

I've tried to see differences between on/off within Overwatch/CS2, but `GetProcessDefaultCpuSets` returned `DefaultCpuSetCount=0` even while Game Mode was active. Other games I tested were Forza Horizon 5/Cyberpunk 2077 which don't register with Game Mode at all.

During registration ([Apply Resource Policies](https://noverse.dev/docs/win-config/system/game-mode/#apply-resource-policies)), [`RmpGameModeAcquireCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeAcquireCpuSetAllocation@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_P.c) asks the CPU set manager for a valid allocation, the CPU set manager chooses the actual CPU sets from the request and current system CPU set state, then [`RmpCpuSetManagerApplySystemAllowedMask`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpCpuSetManagerApplySystemAllowedMask@@YAJPEAU_RM_CPU_SET_MANAGER@@@Z.c) can reduce the CPU sets available to general system activity. [`RmpGameModeTryApplyCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyCpuSetAllocation@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_.c) then applies that allocation to the registered process.

The final calls are [`RmpSystemSetProcessDefaultCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessDefaultCpuSets@@YAJPEAXPEA_K@Z.c) (preferred selection), [`RmpSystemSetProcessConstrainedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessConstrainedCpuSets@@YAJPEAXE@Z.c) (limit to selected CPU sets), [`RmpSystemSetProcessAllowedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetProcessAllowedCpuSets@@YAJPEAXPEA_K@Z.c) (updated when the allocation changes).

When Game Mode is removed from the process, [`RmpGameModeUnapplyCpuSetAllocation`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeUnapplyCpuSetAllocation@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_P.c) clears default CPU sets etc.

### GPU scheduler & GPU memory budget

Game Mode changes graphics policy through D3DKMT calls, the service applies a scheduler yield percentage with `D3DKMTSetYieldPercentage` and a GPU memory budget target with `D3DKMTSetMemoryBudgetTarget`.

| Part | Description |
| --- | --- |
| GPU yield percentage | Scheduler policy value passed to `D3DKMTSetYieldPercentage`, Game Mode accepts `2-10`. From my understanding a lower yield value means that the game yields less GPU scheduling time in relation to other work and the opposite. |
| Game GPU memory budget percentage | First budget target passed to `D3DKMTSetMemoryBudgetTarget`, the default fallback is `50`. Note that this is a "target" not a reservation of VRAM. |
| System compositor GPU memory budget percentage | Second budget target passed to `D3DKMTSetMemoryBudgetTarget`, the default fallback is `30`. |

The RM initializer starts with `10/50/30`, but the shell request builder normally uses the HKCU fallback values `2/50/30` when no valid per game profile is present (see below). 

The stored GPU profile is created as four bytes, but the Game Mode service only receives the yield byte, the game budget byte, the system compositor budget byte, the fourth byte is calculated by [`GameModeConfigurationServer::_SaveToGameConfigStore`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/Windows-Gaming-Preview/-_SaveToGameConfigStore@GameModeConfigurationServer@GamesEnumeration@Preview@Gaming@Windows@@AEA.c) as `100 - game - system compositor`. [`GameModeConfigurationServer::_LoadPropertyValues`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/Windows-Gaming-Preview/-_LoadPropertyValues@GameModeConfigurationServer@GamesEnumeration@Preview@Gaming@Windows@@AEAAJX.c) shows only the top three bytes again, I'll just call the fourth byte the stored remainder.

```c
// SetGameGpuProfile
if ( a4 + a6 + (unsigned __int8)a5 != 100 ) // game budget + system compositor budget + stored remainder == 100
{
  v6 = -2147024809;
  v7 = 397LL;
LABEL_7:
  wil::details::in1diag3::Return_Hr(
    retaddr,
    (void *)v7,
    (int)"onecoreuap\\xbox\\windows.gaming.preview\\dll\\gameconfigutils.cpp",
    (const char *)v6);
  return v6;
}
if ( a3 > 0x64u ) // yield byte <= 100
{
  v6 = -2147024809;
  v7 = 402LL;
  goto LABEL_7;
}
v9 = (__int128)*a2;
a5 = a6 | (((unsigned __int8)a5 | ((a4 | (a3 << 8)) << 8)) << 8); // yield, game budget, system compositor budget, stored remainder
```

`GetGameModeRequest` then builds the service request from either the per game profile or the HKCU fallback values, if the per game profile is absent or invalid, it uses the fallback values.

```c
// RmGameModeInitializeResourceRequest
*(_DWORD *)(a1 + 16) = 10; // GPU yield
*(_DWORD *)(a1 + 20) = 50; // game GPU memory budget
*(_DWORD *)(a1 + 24) = 30; // system compositor GPU memory budget
```

```c
// BroadcastDVRComponent::GetGameModeRequest
DWORD = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuGameMemoryBudgetPercentage", &v53);
v10 = 50;
if ( DWORD >= 0 )
  v10 = v53;
v46 = v10;
v11 = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuDwmMemoryBudgetPercentage", &v53);
v12 = 30;
if ( v11 >= 0 )
  v12 = v53;
v47 = v12;
v13 = SHRegGetDWORD(HKEY_CURRENT_USER, L"Software\\Microsoft\\GameBar", L"GpuYieldPercentage", &v53);
v14 = 2;
if ( v13 >= 0 )
  v14 = v53;
v45 = v14;
```

```c
// BroadcastDVRComponent::GetGameModeRequest
if ( !v15 )
  goto LABEL_44; // no GPU profile, use HKCU fallback values
*v33 = HIBYTE(v15); // GPU yield
if ( HIBYTE(v15) > 0xAu )
  *v34 = 100 - HIBYTE(v15);
v35 = v45;
*(_DWORD *)(a4 + 20) = BYTE2(v15); // GPU memory budget
v36 = BYTE1(v15);
*(_DWORD *)(a4 + 24) = BYTE1(v15); // system compositor budget
LABEL_45:
v37 = *(_DWORD *)(a4 + 20);
if ( !v37 && !v36 )
{
  v38 = 1;
LABEL_81:
  v17 = 0;
  goto LABEL_82;
}
v38 = 0;
if ( v37 < 0x64 && v36 < 0x64 )
  goto LABEL_81;
LABEL_82:
if ( v38 || v17 || v37 + v36 >= 0x64 ) // invalid pair falls back to HKCU values
{
  *(_DWORD *)(a4 + 20) = v46;
  *(_DWORD *)(a4 + 24) = v47;
}
result = *v34 - 2;
if ( (unsigned int)result > 8 )
  *v34 = v35; // invalid yield falls back to HKCU value
```

The service validates the final request in [`RmpGameModeIsResourceRequestValid`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeIsResourceRequestValid@@YAEPEAU_RM_SERVICE_GLOBALS@@PEAU_RM_GAME_MODE_RESOURCE_REQUE.c) with ranges listed in [Validate in the Service](https://noverse.dev/docs/win-config/system/game-mode/#validate-in-the-service). The actual graphics update is in [`RmpGameModeTryApplyGraphicsPriority`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyGraphicsPriority@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_.c), Game Mode saves the original graphics settings during initialization, applies the Game Mode values while active, and restores the saved values when Game Mode is removed.

```c
// RmpGameModeTryApplyGraphicsPriority
v7 = *v3;
v20 = 0;
v21 = 0;
v22 = v7; // accepted GPU yield value
v19 = 16;
v6 = D3DKMTSetYieldPercentage(&v19);
v8 = v3;
if ( v6 < 0 )
  goto LABEL_6;
v9 = *((_DWORD *)a2 + 33);
v20 = 0;
v2 = 1;
v21 = v9; // accepted game budget target
v22 = *((_DWORD *)a2 + 34); // accepted system compositor budget target
v19 = 16;
v6 = D3DKMTSetMemoryBudgetTarget(&v19);
```

### Game Mode Power Profile WNF State

Game Mode can update `WNF_SEB_GAME_MODE` through [`RmpSystemEnableDisableGameModePowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemEnableDisableGameModePowerProfile@@YAJE@Z.c), the apply function is [`RmpGameModeTryApplyPowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplyPowerProfile@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPIENT_PROC.c), it applies only to the primary process and only when the request builder asks for this policy.

WNF = Windows Notification Facility

> "*The Windows Notification Facility, or WNF, is the core underpinning of a modern registrationless publisher/subscriber mechanism*"
>
> "*The ability to define a state name that can be subscribed to, or published to by arbitrary processes*"
>
> "*The ability to associate such a state name with a payload of up to 4 KB*"
>
> "*The Power Manager and various related components use WNF to signal actions*"
>
> — Microsoft, [Windows Internals E7, P2: Chapter 8, System mechanisms](https://github.com/nohuto/windows-books/releases/download/7th-Edition/Windows-Internals-E7-P2.pdf)

That is why the Game Mode power part uses WNF, it writes `WNF_SEB_GAME_MODE`, and the power/SEB side can get that state and apply the `GameMode` processor power profile.

Microsoft documents `GameMode` as a processor power management profile that OEMs can configure through provisioning packages.

> "*The power profiles are used by the power processor engine to adapt the performance and parking algorithm on various system use cases.*"
> "*GameMode profile is enabled when the 'Game Mode' setting toggle is turned on and the user is playing a game.*"
>
> — Microsoft, [Processor power management options](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#power-profiles)

> "*Power profiles provide system wide configuration of processor power management, impacting all running workloads equally.*"
>
> — Microsoft, [Processor power management options](https://github.com/nohuto/win-config/blob/main/power/assets/reference/power-settings/configure-processor-power-management-options.md#quality-of-service)

```c
// RmpGameModeTryApplyPowerProfile
if ( *((_DWORD *)a2 + 26) || (*((_BYTE *)a2 + 144) & 8) == 0 )
  return 255LL;
v2 = RmpSystemEnableDisableGameModePowerProfile(1u);
if ( v2 < 0 )
  MicrosoftTelemetryAssertTriggeredNoArgs();
```

```c
// RmpSystemEnableDisableGameModePowerProfile
v2 = 0xFFFFFFFF00000001uLL;
if ( a1 )
  LODWORD(v2) = 3;
return NtUpdateWnfStateData(&WNF_SEB_GAME_MODE, &v2, 8LL, 0LL, 0LL, 0, 0);
```

When enabled, WNF uses low value `3`, when disabled, it uses low value `1`. The high value stays `0xFFFFFFFF` in both cases.

You can use [`gm_effects`](https://noverse.dev/docs/win-config/system/game-mode/#gm_effects) to see what value is set.

[`BroadcastDVRComponent::IsUsingPowerProfile`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/twinui-pcshell/-IsUsingPowerProfile@BroadcastDVRComponent@@AEAA_NAEBU_GUID@@@Z.c) checks whether the active power scheme is `GUID_MIN_POWER_SAVINGS` (High Performance), the request builder uses that result as "already using a performance plan". In the default cases, it asks the service for the GameMode power profile only when the current plan isn't High Performance (`GUID_MIN_POWER_SAVINGS` has `PROCTHROTTLEMIN`/`PROCTHROTTLEMIN1` at `100` by default).

```c
// BroadcastDVRComponent::IsUsingPowerProfile
v2 = PowerGetActiveScheme(0LL, &v6) == 0;
if ( v7 )
  hMem = v6;
if ( v2 )
{
  v3 = *(_QWORD *)&hMem->Data1 - *(_QWORD *)&GUID_MIN_POWER_SAVINGS.Data1;
  if ( *(_QWORD *)&hMem->Data1 == *(_QWORD *)&GUID_MIN_POWER_SAVINGS.Data1 )
    v3 = *(_QWORD *)hMem->Data4 - *(_QWORD *)GUID_MIN_POWER_SAVINGS.Data4;
  v4 = v3 == 0;
}
```

### Expanded Resource Extension Notification

When the optional extension is present, RM notifies it when Game Mode has active policy recipients and when the main Game Mode process enters or leaves expanded resource mode. [`PsmInitializeServiceExtension4`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/PsmInitializeServiceExtension4.c) shows why this is optional, the service only initializes the extension when the extension functions are present.

```c
// PsmInitializeServiceExtension4
if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent(v4) ) // extension exists
{
  v10[0] = RmGameModeCpuSetManagerCreateClientContext;
  v10[1] = RmGameModeCpuSetManagerAcquireExplicitCpuSets;
  v10[2] = RmGameModeCpuSetManagerRegisterProcessWithAllocation;
  v10[3] = RmGameModeCpuSetManagerReleaseAllocation;
  v10[4] = RmGameModeCpuSetManagerReleaseProcessRegistration;
  InitializeGameModeExtension(v10, v8); // give extension those callbacks + RM service globals
}
```

[`RmpGameModeNotifyExtensionRecipientsPresent`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeNotifyExtensionRecipientsPresent@@YAXPEAU_RM_GAME_MODE_CONTEXT@@E@Z.c) sends the global "Game Mode recipients exist" state, it only calls the extension when that state changes.

```c
// RmpGameModeNotifyExtensionRecipientsPresent
if ( *((_BYTE *)a1 + 140) != a2 ) // cached state differs from new state
{
  v4 = 0;
  *((_DWORD *)a1 + 20) = 0;
  RtlReleaseSRWLockExclusive((char *)a1 + 72);
  if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent() ) // extension exists
  {
    LOBYTE(v4) = a2 != 0; // convert state to boolean
    NotifyGameModeExtensionRecipientsPresent(v4); // notify whether Game Mode recipients exist
  }
  *((_BYTE *)a1 + 140) = a2; // cache the state after notification
  RtlAcquireSRWLockExclusive((char *)a1 + 72);
  *((_DWORD *)a1 + 20) = GetCurrentThreadId();
}
```

[`RmpGameModeTryApplySystemExtensionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeTryApplySystemExtensionPolicy@@YAJPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIP.c) sends the enabled state for the main Game Mode recipient (related or auxiliary recipients skip this). [`RmpGameModeUnapplySystemExtensionPolicy`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpGameModeUnapplySystemExtensionPolicy@@YAXPEAU_RM_GAME_MODE_CONTEXT@@PEAU_RM_GAME_MODE_RECIPI.c) sends the disabled state when the policy is removed.

```c
// RmpGameModeTryApplySystemExtensionPolicy
if ( *((_DWORD *)a2 + 26) )
  return 255LL; // not the main recipient = skipped
RmpSystemNotifyGameModeExtensionStateChange(*((void **)a2 + 5), 1u); // enabled for this process handle
```

```c
// RmpGameModeUnapplySystemExtensionPolicy
RmpSystemNotifyGameModeExtensionStateChange(a2[5], 0); // disabled for this process handle
```

```c
// RmpSystemNotifyGameModeExtensionStateChange
v4 = IsNotifyGameModeExtensionRecipientsPresentPresent();
v5 = 0LL;
if ( v4 )
{
  LOBYTE(v5) = a2 != 0; // enabled/disabled
  NotifySystemExpandedResourceModeStateChange(a1, v5); // process handle + expanded resource mode state
}
```

The same optional extension can also change how the system allowed CPU set mask is applied, [`RmpSystemSetSystemAllowedCpuSets`](https://github.com/nohuto/decompiled-pseudocode/blob/main/11-23H2/PsmServiceExtHost/-RmpSystemSetSystemAllowedCpuSets@@YAJPEA_K@Z.c) uses the extension when it's present, otherwise it writes the mask directly through `NtSetSystemInformation`.

```c
// RmpSystemSetSystemAllowedCpuSets
if ( (unsigned __int8)IsNotifyGameModeExtensionRecipientsPresentPresent(SystemInformation) )
  return DelegateSetSystemAllowedCpuSets(SystemInformation, v2); // extension handles system allowed CPU set
else
  return NtSetSystemInformation(SystemPlugPlayBusInformation|0x80, SystemInformation, v2);
```

## Summary (& Opinion)

- WU driver updates/automatic restarts/restart notifications shouldn't be enabled, so that behavior doesn't matter.
- [Process priority class](https://noverse.dev/docs/win-config/system/game-mode/#process-priority-class) can prevent a game from setting itself to `REALTIME_PRIORITY_CLASS` as Game Mode would overwrite that with `NORMAL_PRIORITY_CLASS`. If a game doesn't have such issues, the priority classes Game Mode uses are usually similar to what normal games already use.
- Game Mode prevents the FG boost from happening (tested on 23H2), if you don't use `PsPrioritySeparation` FG boost (`1`/`2`), then this doesn't matter (follow '[Watching the FG Priority Boost](https://noverse.dev/docs/win-config/system/priority-separation/#watching-the-fg-priority-boost)' but with the game, as said in the section).
- I haven't seen any game yet where Game Mode applied [CPU Sets](https://noverse.dev/docs/win-config/system/game-mode/#cpu-sets) through `GetProcessDefaultCpuSets`, if Game Mode chose proper CPU set IDs, this could be useful, but I wouldn't trust Microsoft with that.
- [GPU policy](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget) should only be noticeable if the system has GPU scheduling (`D3DKMTSetYieldPercentage`, means when there's a lot of GPU work in the background, see '[GPU yield percentage](https://noverse.dev/docs/win-config/system/game-mode/#gpu-scheduler--gpu-memory-budget)' description?) or GPU memory issues (if VRAM is kind of used while background processes need GPU memory, e.g. high quality captures?).
- [Game Mode power profile](https://noverse.dev/docs/win-config/system/game-mode/#game-mode-power-profile-wnf-state) doesn't seem to have any effect when the active scheme is already `GUID_MIN_POWER_SAVINGS` or a modified version of that scheme (must be GUID of `GUID_MIN_POWER_SAVINGS`, so not a copied version of it).

FPS testing isn't a good way to decide whether Game Mode has any benefits for you, rather check whether the game registers with Game Mode at all, whether the game already sets priority class correctly itself, whether CPU sets are applied, and if they are applied, which CPU set IDs are used. Use [gm_effects](https://noverse.dev/docs/win-config/system/game-mode/#gm_effects)/WPR (see below, I'll add more on it soon to see if it's actually useful, since wevtutil doesn't show events)/SI for it.

```powershell
Provider: Microsoft.Windows.ResourceManager
GUID:     {4180C4F7-E238-5519-338F-EC214F0B49AA}

resourceFileName: %SystemRoot%\system32\PsmServiceExtHost.dll
messageFileName:  %SystemRoot%\system32\PsmServiceExtHost.dll
```

