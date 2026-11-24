# Administrator Account

This security setting determines whether the [local Administrator account](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/accounts-administrator-account-status) is enabled or disabled. The following conditions prevent disabling the Administrator account, even if this security setting is disabled.

- The Administrator account is currently in use
- The Administrators group has no other members
- All other members of the Administrators group are:
  - Disabled
  - Listed in the [Deny log on locally](https://learn.microsoft.com/en-us/previous-versions/windows/it-pro/windows-10/security/threat-protection/security-policy-settings/deny-log-on-locally) User Rights Assignment
  
If the Administrator account is disabled, you can't enable it if the password doesn't meet requirements. In this case, another member of the Administrators group must reset the password.

The option currently finds the account by its RID `500` (SID `S-1-5-21-<domain>-500`, [Local accounts](https://learn.microsoft.com/en-us/windows/security/identity-protection/access-control/local-accounts)).

## Best practices

Disabling the administrator account can become a maintenance issue under certain circumstances. For example, in a domain environment, if the secure channel that constitutes your connection fails for any reason, and there's no other local administrator account, you must restart the computer in safe mode to fix the problem that broke your connection status.

## Vulnerability

Before the October 2022 update the built-in Administrator account couldn't be locked out, no matter how many failed logons it accrued, which made it a prime target for brute-force attacks. Windows 11 22H2 and newer installs enable [Allow Administrator account lockout](https://support.microsoft.com/en-us/topic/kb5020282-account-lockout-available-for-built-in-local-administrators-bce45c4d-f28d-43ad-b6fe-70156cb2dc00) at setup, which locks it out for network logons (RDP), console logons still work. Also, this account has a well-known security identifier (SID), and there are non-Microsoft tools that allow authentication by using the SID rather than the account name. Therefore, even if you rename the Administrator account, an attacker could launch a brute-force attack by using the SID to sign in. All other accounts that are members of the Administrator's group have the safeguard of locking out the account if the number of failed logons exceeds its configured maximum.

