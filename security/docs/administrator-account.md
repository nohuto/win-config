# Administrator Account

This security setting determines whether the [local Administrator account](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/accounts-administrator-account-status) is enabled or disabled. The following conditions prevent disabling the Administrator account, even if this security setting is disabled.

- he Administrator account is currently in use
- The Administrators group has no other members
- All other members of the Administrators group are:
  - Disabled
  - Listed in the [Deny log on locally](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/deny-log-on-locally) User Rights Assignment
  
If the Administrator account is disabled, you can't enable it if the password doesn't meet requirements. In this case, another member of the Administrators group must reset the password.

## Best practices

Disabling the administrator account can become a maintenance issue under certain circumstances. For example, in a domain environment, if the secure channel that constitutes your connection fails for any reason, and there's no other local administrator account, you must restart the computer in safe mode to fix the problem that broke your connection status.

## Vulnerability

The built-in administrator account can't be locked out no matter how many failed logons it accrues, which makes it a prime target for brute-force attacks that attempt to guess passwords. Also, this account has a well-known security identifier (SID), and there are non-Microsoft tools that allow authentication by using the SID rather than the account name. Therefore, even if you rename the Administrator account, an attacker could launch a brute-force attack by using the SID to sign in. All other accounts that are members of the Administrator's group have the safeguard of locking out the account if the number of failed logons exceeds its configured maximum.

