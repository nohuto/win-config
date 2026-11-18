# Disable Thumbnail Caching

Disables persistent File Explorer thumbnail caching so previews are less likely to remain stored after browsing folders. Windows normally rebuilds thumbnail caches automatically (use `Thumbnail Cache` option in 'Cleanup' section to clear it).

This improves privacy mainly by reducing leftover preview artifacts for images, videos, documents, and other shell items. Microsoft explicitly notes that the thumbnail cache can be read by everyone on shared or security sensitive systems, and the related network folder thumbnail policies note that allowing thumbnail use on network folders can expose computers to security risks.

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Turn off the caching of thumbnails in hidden thumbs.db files](https://noverse.dev/policies?p=Thumbnails*DisableThumbsDBOnNetworkFolders) | `HKCU\Software\Policies\Microsoft\Windows\Explorer` | `DisableThumbsDBOnNetworkFolders` |
| [Turn off caching of thumbnail pictures](https://noverse.dev/policies?p=WindowsExplorer*NoCacheThumbNailPictures) | `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `NoThumbnailCache` |

