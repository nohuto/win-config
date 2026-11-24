# Disable Activity History

> "*Activity History shows a history of activities a user has performed and can even synchronize activities across multiple devices for the same user. Synchronization across devices only works when a user signs in with the same account. This feature is available in versions of Windows released prior to January 2024, and has been discontinued in new versions of Windows.*"
>
> — Microsoft, [Essential services and connected experiences](https://learn.microsoft.com/en-us/windows/privacy/essential-services-and-connected-experiences)

`EnableActivityFeed` enables or disables publishing and syncing of activities across devices. `PublishUserActivities` allows or blocks local publishing of user activities. `UploadUserActivities` allows or blocks uploading of user activities to the cloud, deletion is not affected.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enables Activity Feed](https://noverse.dev/policies?p=OSPolicy*EnableActivityFeed) | `HKLM\Software\Policies\Microsoft\Windows\System` | `EnableActivityFeed` |
| [Allow publishing of User Activities](https://noverse.dev/policies?p=OSPolicy*PublishUserActivities) | `HKLM\Software\Policies\Microsoft\Windows\System` | `PublishUserActivities` |
| [Allow upload of User Activities](https://noverse.dev/policies?p=OSPolicy*UploadUserActivities) | `HKLM\Software\Policies\Microsoft\Windows\System` | `UploadUserActivities` |

