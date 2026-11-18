# Settings Page Visibility

It controls which pages in the windows settings app are visible (blocked pages are removed from view and direct access redirects to the main settings page).

> "*This policy allows an administrator to block a given set of pages from the System Settings app. Blocked pages will not be visible in the app, and if all pages in a category are blocked the category will be hidden as well. Direct navigation to a blocked page via URI, context menu in Explorer or other means will result in the front page of Settings being shown instead.*"

```c
HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer : SettingsPageVisibility // REG_SZ
```

- `showonly:` followed by a semicolon separated list of page identifiers to allow
- `hide:` followed by a list of pages to block

Page identifiers are the part after `ms-settings:` in a settings URI.

### Example

`showonly:bluetooth` only shows the `Bluetooth` page
`hide:bluetooth;windowsdefender` hides the `Bluetooth` & `Windows Security` pages

See a list of all categories of `ms-settings` URIs [here](https://learn.microsoft.com/en-us/windows/apps/develop/launch/launch-settings-app#ms-settings-uri-scheme-reference).

### Example Value

This is what the option currently uses, whenever you want to add/remove a section, edit the value.

```bat
hide:home;recovery;troubleshoot;activation;network-dialup;deviceusage;maps;emailandaccounts;otherusers;sync;family-group;workplace;speech;findmydevice;windowsdefender
```

## [Windows Policies](https://noverse.dev/policies)

| Policy | Key Path | Value Name |
| --- | --- | --- |
| [Settings Page Visibility](https://noverse.dev/policies?p=ControlPanel*SettingsPageVisibility) | `HKLM\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` <br> `HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer` | `SettingsPageVisibility` |
