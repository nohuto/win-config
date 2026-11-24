# Disable Recall

> "*Allows you to control whether Windows saves snapshots of the screen and analyzes the user's activity on their device. If you enable this policy setting, Windows will not be able to save snapshots and users won't be able to search for or browse through their historical device activity using Recall. If you disable or do not configure this policy setting, Windows will save snapshots of the screen and users will be able to search for or browse through a timeline of their past activities using Recall.*"

Note that Recall only exists on Copilot+ PCs with 24H2+, on every other PC the option changes nothing.

## Suboption

### Disable ClickToDo

> "*Click to Do lets people take action on content on their screens. When activated, it takes a screenshot of their screen and analyzes it to present actions. Click to Do ends when they exit it, and it can't take screenshots while closed. Screenshot analysis is always performed locally on their device. By default, Click to Do is enabled for users. This policy setting allows you to determine whether Click to Do is available for users on their device. When the policy is enabled, the Click to Do component and entry points will not be available to users. When the policy is disabled, users will have Click to Do available on their device.*"

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off saving snapshots for use with Recall](https://noverse.dev/policies?p=WindowsCopilot*DisableAIDataAnalysis) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `DisableAIDataAnalysis` |
| [Allow Recall to be enabled](https://noverse.dev/policies?p=WindowsCopilot*AllowRecallEnablement) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `AllowRecallEnablement` |
| [Disable Click to Do](https://noverse.dev/policies?p=WindowsCopilot*DisableClickToDo) | `HKLM\SOFTWARE\Policies\Microsoft\Windows\WindowsAI`<br>`HKCU\SOFTWARE\Policies\Microsoft\Windows\WindowsAI` | `DisableClickToDo` |

