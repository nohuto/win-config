# Disable MDM Enrollment

`DisableRegistration`:
> "*This policy setting specifies whether Mobile Device Management (MDM) Enrollment is allowed. When MDM is enabled, it allows the user to have the computer remotely managed by a MDM Server. If you do not configure this policy setting, MDM Enrollment will be enabled. If you enable this policy setting, MDM Enrollment will be disabled for all users. It will not unenroll existing MDM enrollments.If you disable this policy setting, MDM Enrollment will be enabled for all users.*"

`AutoEnrollMDM`:
> "*This policy setting specifies whether to automatically enroll the device to the Mobile Device Management (MDM) service configured in Azure Active Directory (Azure AD). If the enrollment is successful, the device will remotely managed by the MDM service. Important: The device must be registered in Azure AD for enrollment to succeed. If you do not configure this policy setting, automatic MDM enrollment will not be initiated. If you enable this policy setting, a task is created to initiate enrollment of the device to MDM service specified in the Azure AD. If you disable this policy setting, MDM will be unenrolled.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Disable MDM Enrollment](https://noverse.dev/policies?p=MDM*MDM_MDM_DisplayName) | `HKLM\Software\Policies\Microsoft\Windows\CurrentVersion\MDM` | `DisableRegistration` |
| [Enable automatic MDM enrollment using default Azure AD credentials](https://noverse.dev/policies?p=MDM*MDM_JoinMDM_DisplayName) | `HKLM\Software\Policies\Microsoft\Windows\CurrentVersion\MDM` | `AutoEnrollMDM`<br>`UseAADCredentialType`<br>`MDMApplicationId` |

