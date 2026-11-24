# Disable Downloads Blocking

Windows adds a hidden tag called [`Zone.Identifier`](https://www.cyberengage.org/post/unveiling-file-origins-the-role-of-alternate-data-streams-ads-zone-identifier-in-forensic-inve) to files downloaded from the internet. This tag (also known as MotW) stores info about the file's origin and helps apply security warnings, see files including the tag with:

```powershell
gi * -Stream "Zone.Identifier" -ErrorAction SilentlyContinue
```

Using `SaveZoneInformation = 1` causes Windows to stop adding `Zone.Identifier` to files you download or save from attachments, see policy at the end.

> "*This policy setting allows you to manage whether Windows marks file attachments with information about their zone of origin (such as restricted, Internet, intranet, local). This requires NTFS in order to function correctly, and will fail without notice on FAT32. By not preserving the zone information, Windows cannot make proper risk assessments.*"

![](https://github.com/nohuto/win-config/blob/main/security/images/downblocking.png?raw=true)

## ZoneID Data

**ZoneID** (`HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings\Zones`) - number indicating the security zone the file came from:
`0` - Local machine
`1` - Local intranet (internal network)
`2` - Trusted sites
`3` - Internet (mostly web downloads)
`4` - Restricted sites ([`URLZONE_UNTRUSTED`](https://learn.microsoft.com/en-us/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537175(v=vs.85)))

## Unblock-File

Files downloaded from the internet still getting blocked? Unblock it/them with (one of them):
```powershell
Unblock-File -Path "C:\Path\Script.ps1" # one file

dir C:\Path\*Files* | Unblock-File # several files
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Do not preserve zone information in file attachments](https://noverse.dev/policies?p=AttachmentManager*AM_MarkZoneOnSavedAtttachments) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Attachments` | `SaveZoneInformation` |

