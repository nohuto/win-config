# File System Values

Small documentation on several values the option applies, see links below for more details.

### Registry Values

This list isn't complete yet, see [FileSystem](https://github.com/nohuto/regkit/blob/main/assets/records/FileSystem.txt) for all values that get read on boot ([boot capture guide](https://noverse.dev/docs/regkit/guides/wpr-wpa/)).

| Value | Description |
| ----- | ------------ |
| `DisableDeleteNotification` | 0 = TRIM/UNMAP enabled, 1 = disabled. Controls whether delete operations send trim/unmap notifications to the underlying storage. |
| `DontVerifyRandomDrivers` | 0 = Driver Verifier may pick random drivers, 1 = random selection suppressed, so only explicitly chosen drivers are verified. |
| [`LongPathsEnabled`](https://learn.microsoft.com/en-us/windows/win32/fileio/maximum-file-path-limitation?tabs=registry) | 0 = legacy `MAX_PATH` limit, 1 = Win32 long paths enabled (paths up to ~32k characters for apps and policies that opt in). |
| `NtfsAllowExtendedCharacter8dot3Rename` | 0 = 8.3 short names restricted to basic ASCII, 1 = extended characters (including diacritics). |
| `NtfsBugcheckOnCorrupt` | 0 = NTFS attempts self healing without forcing a bugcheck, 1 = triggers a bugcheck when corruption is detected on an NTFS volume, avoiding "silent" data loss with self healing NTFS. |
| `NtfsDisable8dot3NameCreation` | Disables the creation of 8.3 character-length file names on FAT- and NTFS-formatted volumes.<br>0: Enables 8dot3 name creation for all volumes on the system.<br>1: Disables 8dot3 name creation for all volumes on the system.<br>2: Sets 8dot3 name creation on a per volume basis.<br>3: Disables 8dot3 name creation for all volumes except the system volume. |
| `NtfsDisableCompression` | 0 = NTFS compression allowed, 1 = new compressed files/folders cannot be created (existing compressed data remains readable). |
| `NtfsDisableCompressionLimit` | 0 = when a compressed file gets highly fragmented, NTFS stops compressing new extents so the file can grow larger uncompressed, 1 = disables this behavior and enforces the internal compression limit. |
| `NtfsDisableEncryption` | 0 = NTFS EFS file/folder encryption available, 1 = EFS disabled on NTFS volumes. |
| `NTFSDisableLastAccessUpdate` | Controls Last Access Time updates on NTFS files/directories. |
| `NtfsDisableSpotCorruptionHandling` | 0 = NTFS spot corruption handling active, 1 = disabled, so NTFS relies on manual tools. Also allows running CHKDSK to analyze a volume online without taking it offline. |
| `NtfsEncryptPagingFile` | 0 = pagefile.sys stored unencrypted, 1 = paging file encrypted. |
| `NtfsMemoryUsage` | Configures the internal cache levels of NTFS paged-pool memory and NTFS nonpaged-pool memory. |
| `NtfsMftZoneReservation` | Sets reserved NTFS MFT zone size as 200 MB x value: 1 = 200 MB (default), up to 4 = 800 MB. Larger values reduce MFT fragmentation on volumes with many small files. |
| `RefsDisableLastAccessUpdate` | Related to NTFSDisableLastAccessUpdate (both get set via disablelastaccess). |
| `SymlinkXToXEvaluation` | 0 = x->x symlinks not followed, 1 = resolved (X = Local/Remote). Symlinksare shortcuts or references that point to a file or folder in another location, like a portal. They're not duplicates, just pointers. File at: `C:\Projects\Game\assets\logo.png`, Symlink: `C:\Users\YourName\Desktop\logo.png`. |
| `Win31FileSystem` | 0 = standard modern FAT behavior (long filenames, richer timestamps), 1 = legacy Windows 3.1 - compatible mode with stricter 8.3 naming and older timestamp semantics. |

- [system/assets/pseudocode | filesystem-NtfsUpdateDynamicRegistrySettings.c](https://github.com/nohuto/win-config/blob/main/system/assets/pseudocode/filesystem-NtfsUpdateDynamicRegistrySettings.c)

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Enable Win32 long paths](https://noverse.dev/policies?p=FileSys*LongPathsEnabled) | `HKLM\System\CurrentControlSet\Control\FileSystem` | `LongPathsEnabled` |

