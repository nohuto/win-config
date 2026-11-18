# Product Key

> "*Some servicing operations require the product key to be available in the registry during Out of Box Experience (OOBE) operations. The /cpky option removes the product key from the registry to prevent this key from being stolen by malicious code. For retail installations that deploy keys, the best practice is to run this option. This option isn't required for MAK and KMS host keys, because this is the default behavior for those keys. This option is required only for other types of keys whose default behavior isn't to clear the key from the registry.*"
>
> — Microsoft Learn, [Slmgr.vbs options](https://learn.microsoft.com/en-us/windows-server/get-started/activation-slmgr-vbs-options#advanced-options)

Implementation details (from `slmgr.vbs` and `sppwmi.mof`):
```vbscript
ElseIf strOption = GetResource("L_optClearPKeyFromRegistry") Then
    ClearPKeyFromRegistry

Private Sub ClearPKeyFromRegistry()
    set objService = GetServiceObject("Version")
    objService.ClearProductKeyFromRegistry()
End Sub
```
```mof
// %SystemRoot%\System32\wbem\sppwmi.mof (root\cimv2)
[dynamic,provider("SppProvider")]
class SoftwareLicensingService
{
  [implemented] uint32 ClearProductKeyFromRegistry();
};
```
So `/cpky` is a thin wrapper over the `SoftwareLicensingService.ClearProductKeyFromRegistry` WMI method. It clears the stored product key from the registry to reduce disclosure risk, but it does not uninstall the key or change activation state.

PowerShell equivalent?
```powershell
$svc = Get-CimInstance -Namespace root\cimv2 -ClassName SoftwareLicensingService
Invoke-CimMethod -InputObject $svc -MethodName ClearProductKeyFromRegistry
```

