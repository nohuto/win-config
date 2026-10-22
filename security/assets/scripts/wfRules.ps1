# This PS is a part of the WinConfig documentation
# https://noverse.dev/docs/win-config/security/windows-firewall
# https://github.com/nohuto
# https://discord.noverse.dev

[CmdletBinding(SupportsShouldProcess, PositionalBinding = $false)]
param([switch]$a, [switch]$r, [switch]$o, [string]$g, [Parameter(ValueFromRemainingArguments = $true)][string[]]$arguments)
$ErrorActionPreference = 'Stop'

$apply = $a.IsPresent
$reset = $r.IsPresent
$outbound = $o.IsPresent
$managedGroup = if ($g) { $g } else { 'Noverse Rules' }

for ($argumentIndex = 0; $argumentIndex -lt $arguments.Count; $argumentIndex++) {
  $argument = $arguments[$argumentIndex]
  switch ($argument) {
    '--apply' { $apply = $true }
    '--reset' { $reset = $true }
    '--outbound' { $outbound = $true }
    '--managed-group' {
      $argumentIndex++
      if ($argumentIndex -ge $arguments.Count) { throw '--managed-group requires a value' }
      $managedGroup = $arguments[$argumentIndex]
    }
    default { throw "Unsupported argument: $argument" }
  }
}

# Parameters:

# Pattern: wildcard against Name/DisplayName/DisplayGroup/Group
# Name/DisplayName/DisplayGroup/Group: wildcard match against that field
# Direction: Inbound, Outbound, both
# Action: Allow or Block

$disableExistingRulePatterns = @(
  @{ Pattern = 'AllJoyn Router*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Cast to Device*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Cloud Identity*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Connected Devices Platform*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Connected User Experiences and Telemetry*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Core Networking - Teredo*'; Direction = 'Outbound' },
  @{ Pattern = 'Delivery Optimization*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'DIAL protocol server*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'File and Printer Sharing*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Core Networking*'; Direction = 'Inbound' },
  @{ Pattern = 'Microsoft Media Foundation Network*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'mDNS*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Network Discovery*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Proximity sharing over TCP*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Recommended Troubleshooting Client*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Remote Assistance*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'WFD ASP Coordination Protocol*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'WFD Driver-only*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Wi-Fi*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Wireless Display*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Windows Device Management*'; Direction = @('Inbound', 'Outbound') },
  @{ Pattern = 'Windows Feature Experience Pack'; Direction = @('Inbound', 'Outbound') }
)

# Parameters:

# DisplayName: rule name
# Direction: Inbound or Outbound
# Action: Allow or Block
# Program: executable path (wildcards supported)
# Service: service name
# Protocol: TCP, UDP, ICMPv4, ICMPv6, Any
# LocalPort/RemotePort: port number, range, list, Any
# LocalAddress/RemoteAddress: IP, subnet, range, keyword, list, Any
# Package: app package family name
# InterfaceType: Any, Wireless, LAN, RemoteAccess
# Profile: Domain, Private, Public, Any (default)
# Enabled: True (default) or False
# Group: rule group (default $managedGroup)

$rules = @(
  # Outbound allow
  @{ DisplayName = 'Git Remote HTTPS'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files\Git\mingw64\libexec\git-core\git-remote-https.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Steam'; Direction = 'Outbound'; Action = 'Allow'; Program = 'C:\Program Files (x86)\Steam\steam.exe'; Protocol = 'TCP'; RemotePort = @('443') },
  @{ DisplayName = 'Cryptographic Services'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Service = 'CryptSvc'; Protocol = 'TCP'; RemotePort = @('80') },
  @{ DisplayName = 'svchost HTTP/S'; Direction = 'Outbound'; Action = 'Allow'; Program = '%SystemRoot%\System32\svchost.exe'; Protocol = 'TCP'; RemotePort = @('80', '443'); Enabled = 'False' },

  # Outbound block
  @{ DisplayName = 'Steam CEF'; Direction = 'Outbound'; Action = 'Block'; Program = 'C:\Program Files (x86)\Steam\bin\cef\cef.win64\steamwebhelper.exe' },

  # Inbound block
  @{ DisplayName = 'Spotify'; Direction = 'Inbound'; Action = 'Block'; Program = 'C:\Users\nohuto\AppData\Roaming\Spotify\Spotify.exe' },
  @{ DisplayName = 'Steam CEF'; Direction = 'Inbound'; Action = 'Block'; Program = 'C:\Program Files (x86)\Steam\bin\cef\cef.win64\steamwebhelper.exe' }
)

function get-enabledfirewallrules {
  Get-NetFirewallRule -PolicyStore ActiveStore -Enabled True -Direction Inbound,Outbound -ErrorAction Stop
}

function convertto-stringarray {
  param([object]$value)

  if ($null -eq $value) { return @() }
  if ($value -is [System.Array]) {
    $list = [System.Collections.Generic.List[string]]::new($value.Count)
    foreach ($item in $value) {
      $text = "$item".Trim()
      if ($text) { $list.Add($text) }
    }
    return $list.ToArray()
  }

  $text = "$value".Trim()
  if (-not $text) { return @() }
  return @($text)
}

function test-rulevaluepattern {
  param([object]$value,[object]$pattern)

  $patterns = @(convertto-stringarray $pattern)
  if (-not $patterns.Count) { return $true }

  $text = if ($null -eq $value) { '' } else { "$value" }
  foreach ($item in $patterns) {
    if ($text -like $item) { return $true }
  }
  return $false
}

function test-ruletextpattern {
  param([Parameter(Mandatory)][object]$rule, [Parameter(Mandatory)][object]$pattern)

  return (
    (test-rulevaluepattern -value $rule.Name -pattern $pattern) -or
    (test-rulevaluepattern -value $rule.DisplayName -pattern $pattern) -or
    (test-rulevaluepattern -value $rule.DisplayGroup -pattern $pattern) -or
    (test-rulevaluepattern -value $rule.Group -pattern $pattern)
  )
}

function test-rulepattern {
  param([Parameter(Mandatory)][object]$rule,[Parameter(Mandatory)][object]$pattern)

  if ($pattern -is [string]) {
    return (test-ruletextpattern -rule $rule -pattern $pattern)
  }

  if ($pattern -isnot [hashtable]) {
    throw 'Disable patterns must be strings or hashtables'
  }

  foreach ($key in $pattern.Keys) {
    if ($key -eq 'Pattern') {
      if (-not (test-ruletextpattern -rule $rule -pattern $pattern[$key])) {
        return $false
      }
      continue
    }

    switch ($key) {
      'Name' {}
      'DisplayName' {}
      'DisplayGroup' {}
      'Group' {}
      'Direction' {}
      'Action' {}
      default { throw "Unsupported disable pattern key: $key" }
    }

    if (-not (test-rulevaluepattern -value $rule.$key -pattern $pattern[$key])) {
      return $false
    }
  }
  return $true
}

function test-rulematchesdisablepattern {
  param([Parameter(Mandatory)][object]$rule)

  foreach ($pattern in $disableExistingRulePatterns) {
    if (test-rulepattern -rule $rule -pattern $pattern) { return $true }
  }
  return $false
}

function write-rulelog {
  param(
    [Parameter(Mandatory)][object]$rule,
    [string]$status
  )

  $name = if ($rule.DisplayName) { $rule.DisplayName } else { $rule.Name }
  $direction = if ($rule.Direction) { $rule.Direction } else { 'Any' }
  $action = if ($status) { $status } elseif ($rule.Action -eq 'Allow') { 'allowed' } elseif ($rule.Action -eq 'Block') { 'blocked' } else { $rule.Action }
  Write-Host "$name | $direction | $action"
}

function disable-existingrules {
  $disabledRuleNames = @{}
  $matched = $false

  foreach ($rule in get-enabledfirewallrules) {
    if (-not (test-rulematchesdisablepattern -rule $rule)) { continue }

    $matched = $true
    if (-not $disabledRuleNames.ContainsKey($rule.Name)) {
      if ($PSCmdlet.ShouldProcess($rule.DisplayName, 'Disable firewall rule')) {
        $null = Disable-NetFirewallRule -Name $rule.Name -ErrorAction Stop
      }
      $disabledRuleNames[$rule.Name] = $true
      write-rulelog -rule $rule -status 'blocked'
    }
  }

  if (-not $matched) {
    Write-Host 'No enabled firewall rules matched disable patterns'
  }
}

function remove-managedrules {
  $removedRuleNames = @{}
  foreach ($rule in Get-NetFirewallRule -PolicyStore PersistentStore -ErrorAction SilentlyContinue) {
    if (($rule.DisplayGroup -ne $managedGroup -and $rule.Group -ne $managedGroup) -or $removedRuleNames.ContainsKey($rule.Name)) {
      continue
    }

    if ($PSCmdlet.ShouldProcess($rule.DisplayName, 'Remove firewall rule')) {
      $null = Remove-NetFirewallRule -Name $rule.Name -ErrorAction Stop
    }
    $removedRuleNames[$rule.Name] = $true
  }
}

function resolve-ruleprograms {
  param([Parameter(Mandatory)][string]$program)

  $expandedProgram = [Environment]::ExpandEnvironmentVariables($program)
  $programs = [System.Collections.Generic.List[string]]::new()

  if ([System.Management.Automation.WildcardPattern]::ContainsWildcardCharacters($expandedProgram)) {
    foreach ($item in Get-ChildItem -Path $expandedProgram -File -ErrorAction SilentlyContinue) {
      $programs.Add($item.FullName)
    }
    return $programs.ToArray()
  }

  if ([System.IO.File]::Exists($expandedProgram)) {
    $programs.Add([System.IO.Path]::GetFullPath($expandedProgram))
  }

  return $programs.ToArray()
}

function add-managedrules {
  remove-managedrules

  foreach ($rule in $rules) {
    $baseParams = $rule.Clone()
    if (-not $baseParams.ContainsKey('Group')) { $baseParams['Group'] = $managedGroup }
    if (-not $baseParams.ContainsKey('Profile')) { $baseParams['Profile'] = 'Any' }
    if (-not $baseParams.ContainsKey('Enabled')) { $baseParams['Enabled'] = 'True' }

    if ($baseParams.ContainsKey('Program')) {
      $resolvedPrograms = resolve-ruleprograms -program $baseParams['Program']
      if (-not $resolvedPrograms.Count) {
        Write-Host "Missing EXE: $($baseParams['Program'])"
        continue
      }

      foreach ($resolvedProgram in $resolvedPrograms) {
        $params = $baseParams.Clone()
        $params['Program'] = $resolvedProgram
        if ($PSCmdlet.ShouldProcess($params['DisplayName'], 'Create firewall rule')) {
          $null = New-NetFirewallRule @params
        }
        write-rulelog -rule $params
      }
      continue
    }

    if ($PSCmdlet.ShouldProcess($baseParams['DisplayName'], 'Create firewall rule')) {
      $null = New-NetFirewallRule @baseParams
    }
    write-rulelog -rule $baseParams
  }
}

function set-blockedprofiles {
  if ($PSCmdlet.ShouldProcess('Domain, Private, Public firewall profiles', 'Set inbound/outbound block defaults')) {
    Set-NetFirewallProfile -Profile Domain,Private,Public -Enabled True -DefaultInboundAction Block -DefaultOutboundAction Block -NotifyOnListen False -AllowInboundRules True -AllowLocalFirewallRules True -AllowLocalIPsecRules True -AllowUnicastResponseToMulticast False -EnableStealthModeForIPsec True -LogFileName '%SystemRoot%\System32\LogFiles\Firewall\pfirewall.log' -LogMaxSizeKilobytes 16384 -LogBlocked True -LogIgnored True
  }
}

function set-outboundprofiles {
  if ($PSCmdlet.ShouldProcess('Domain, Private, Public firewall profiles', 'Allow outbound and block inbound')) {
    Set-NetFirewallProfile -Profile Domain,Private,Public -Enabled True -DefaultInboundAction Block -DefaultOutboundAction Allow -NotifyOnListen False -AllowInboundRules False -AllowLocalFirewallRules True -AllowLocalIPsecRules True -AllowUnicastResponseToMulticast False -EnableStealthModeForIPsec True -LogFileName '%SystemRoot%\System32\LogFiles\Firewall\pfirewall.log' -LogMaxSizeKilobytes 16384 -LogBlocked True -LogIgnored True
  }
}

function reset-firewall {
  if ($PSCmdlet.ShouldProcess('Windows Firewall policy', 'Reset to Windows defaults')) {
    netsh advfirewall reset
    if ($LASTEXITCODE -ne 0) {
      throw "netsh advfirewall reset failed with exit code $LASTEXITCODE"
    }
  }
}

$selectedFlagCount = [int]$apply + [int]$reset + [int]$outbound
if ($selectedFlagCount -ne 1) {
  throw 'Use one: --apply/-a, --reset/-r, or --outbound/-o'
}

if ($reset) {
  reset-firewall
  return
}

if ($outbound) {
  set-outboundprofiles
  return
}

disable-existingrules
add-managedrules
set-blockedprofiles
