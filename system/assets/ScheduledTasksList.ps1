# (C) 2025 Noverse. All Rights Reserved.
# This PS is a part of the WinConfig documentation
# https://github.com/nohuto
# https://discord.gg/E2ybG4j9jU

Add-Type -TypeDefinition @'
using System;
using System.Text;
using System.Runtime.InteropServices;
public static class ind {
  [DllImport("Shlwapi.dll", CharSet=CharSet.Unicode)]
  public static extern int SHLoadIndirectString(string pszSource, StringBuilder pszOutBuf, int cchOutBuf, IntPtr pvReserved);
}
'@ -ea SilentlyContinue | Out-Null

function tdesc { param([string]$v)
  if ([string]::IsNullOrWhiteSpace($v)) { return $v }
  if ($v -match '^\$\(@(.+)\)$') {$v = '@' + $matches[1]}
  $v = [Environment]::ExpandEnvironmentVariables($v)

  if ($v -notmatch '^@') { return $v }
  $sb = New-Object System.Text.StringBuilder 2048
  $hr = [ind]::SHLoadIndirectString($v, $sb, $sb.Capacity, [IntPtr]::Zero)
  if ($hr -eq 0) { return $sb.ToString() }
  return $v
}

function addv { param([hashtable]$h, [string]$n, $v)
  if ($null -eq $v) { return }
  if ($v -is [string] -and [string]::IsNullOrWhiteSpace($v)) { return }
  if ($v -is [System.Array] -and $v.Count -eq 0) { return }
  $h[$n] = $v
}

function enames { param($n)
  if (-not $n) { return @() }
  $list = New-Object System.Collections.Generic.List[string]
  foreach ($c in $n.ChildNodes) {
    if ($c.NodeType -eq 'Element') { $list.Add($c.LocalName) }
  }
  $list.ToArray()
}

function etexts { param($n)
  if (-not $n) { return @() }
  $list = New-Object System.Collections.Generic.List[string]
  foreach ($c in $n.ChildNodes) {
    if ($c.NodeType -eq 'Element') { $list.Add([string]$c) }
  }
  $list.ToArray()
}

function prinfo { param($pn)
  if (-not $pn) { return @() }
  $list = New-Object System.Collections.Generic.List[object]
  foreach ($p in $pn.Principal) {
    if (-not $p) { continue }
    $item = @{}
    addv $item 'Id' ([string]$p.Id)
    addv $item 'UserId' ([string]$p.UserId)
    addv $item 'GroupId' ([string]$p.GroupId)
    addv $item 'DisplayName' ([string]$p.DisplayName)
    addv $item 'LogonType' ([string]$p.LogonType)
    addv $item 'RunLevel' ([string]$p.RunLevel)
    addv $item 'ProcessTokenSidType' ([string]$p.ProcessTokenSidType)
    if ($p.RequiredPrivileges) {
      $privs = New-Object System.Collections.Generic.List[string]
      foreach ($priv in $p.RequiredPrivileges.Privilege) {
        $text = [string]$priv
        if ($text) { $privs.Add($text) }
      }
      addv $item 'RequiredPrivileges' $privs
    }
    if ($item.Count -gt 0) { $list.Add([pscustomobject]$item) }
  }
  $list.ToArray()
}

function setinfo { param($sn)
  if (-not $sn) { return $null }
  $item = @{}
  addv $item 'AllowStartOnDemand' ([string]$sn.AllowStartOnDemand)
  addv $item 'DisallowStartIfOnBatteries' ([string]$sn.DisallowStartIfOnBatteries)
  addv $item 'StopIfGoingOnBatteries' ([string]$sn.StopIfGoingOnBatteries)
  addv $item 'WakeToRun' ([string]$sn.WakeToRun)
  addv $item 'RunOnlyIfNetworkAvailable' ([string]$sn.RunOnlyIfNetworkAvailable)
  addv $item 'RunOnlyIfIdle' ([string]$sn.RunOnlyIfIdle)
  addv $item 'StartWhenAvailable' ([string]$sn.StartWhenAvailable)
  addv $item 'Enabled' ([string]$sn.Enabled)
  addv $item 'Hidden' ([string]$sn.Hidden)
  addv $item 'ExecutionTimeLimit' ([string]$sn.ExecutionTimeLimit)
  addv $item 'Priority' ([string]$sn.Priority)
  addv $item 'MultipleInstancesPolicy' ([string]$sn.MultipleInstancesPolicy)
  addv $item 'UseUnifiedSchedulingEngine' ([string]$sn.UseUnifiedSchedulingEngine)

  if ($sn.IdleSettings) {
    $idle = @{}
    addv $idle 'Duration' ([string]$sn.IdleSettings.Duration)
    addv $idle 'WaitTimeout' ([string]$sn.IdleSettings.WaitTimeout)
    addv $idle 'StopOnIdleEnd' ([string]$sn.IdleSettings.StopOnIdleEnd)
    addv $idle 'RestartOnIdle' ([string]$sn.IdleSettings.RestartOnIdle)
    if ($idle.Count -gt 0) { $item['IdleSettings'] = $idle }
  }

  if ($sn.NetworkSettings) {
    $net = @{}
    addv $net 'Name' ([string]$sn.NetworkSettings.Name)
    addv $net 'Id' ([string]$sn.NetworkSettings.Id)
    if ($net.Count -gt 0) { $item['NetworkSettings'] = $net }
  }

  if ($sn.MaintenanceSettings) {
    $maint = @{}
    addv $maint 'Period' ([string]$sn.MaintenanceSettings.Period)
    addv $maint 'Deadline' ([string]$sn.MaintenanceSettings.Deadline)
    addv $maint 'Exclusive' ([string]$sn.MaintenanceSettings.Exclusive)
    if ($maint.Count -gt 0) { $item['MaintenanceSettings'] = $maint }
  }

  if ($sn.RestartOnFailure) {
    $rof = @{}
    addv $rof 'Interval' ([string]$sn.RestartOnFailure.Interval)
    addv $rof 'Count' ([string]$sn.RestartOnFailure.Count)
    if ($rof.Count -gt 0) { $item['RestartOnFailure'] = $rof }
  }

  if ($item.Count -gt 0) { [pscustomobject]$item } else { $null }
}

function triginfo { param($tn)
  if (-not $tn) { return @() }
  $list = New-Object System.Collections.Generic.List[object]
  foreach ($t in $tn.ChildNodes) {
    if ($t.NodeType -ne 'Element') { continue }
    $item = @{}
    addv $item 'Type' $t.LocalName
    addv $item 'Enabled' ([string]$t.Enabled)
    addv $item 'StartBoundary' ([string]$t.StartBoundary)
    addv $item 'EndBoundary' ([string]$t.EndBoundary)
    addv $item 'ExecutionTimeLimit' ([string]$t.ExecutionTimeLimit)
    addv $item 'Delay' ([string]$t.Delay)
    addv $item 'RandomDelay' ([string]$t.RandomDelay)
    addv $item 'UserId' ([string]$t.UserId)
    addv $item 'LogonType' ([string]$t.LogonType)
    addv $item 'StateChange' ([string]$t.StateChange)
    addv $item 'Subscription' ([string]$t.Subscription)

    if ($t.Repetition) {
      $rep = @{}
      addv $rep 'Interval' ([string]$t.Repetition.Interval)
      addv $rep 'Duration' ([string]$t.Repetition.Duration)
      addv $rep 'StopAtDurationEnd' ([string]$t.Repetition.StopAtDurationEnd)
      if ($rep.Count -gt 0) { $item['Repetition'] = $rep }
    }

    if ($t.ScheduleByDay) {
      addv $item 'DaysInterval' ([string]$t.ScheduleByDay.DaysInterval)
    }

    if ($t.ScheduleByWeek) {
      $week = @{}
      addv $week 'WeeksInterval' ([string]$t.ScheduleByWeek.WeeksInterval)
      addv $week 'DaysOfWeek' (enames $t.ScheduleByWeek.DaysOfWeek)
      if ($week.Count -gt 0) { $item['ScheduleByWeek'] = $week }
    }

    if ($t.ScheduleByMonth) {
      $month = @{}
      addv $month 'DaysOfMonth' (etexts $t.ScheduleByMonth.DaysOfMonth)
      addv $month 'Months' (enames $t.ScheduleByMonth.Months)
      if ($month.Count -gt 0) { $item['ScheduleByMonth'] = $month }
    }

    if ($t.ScheduleByMonthDayOfWeek) {
      $mdw = @{}
      addv $mdw 'DaysOfWeek' (enames $t.ScheduleByMonthDayOfWeek.DaysOfWeek)
      addv $mdw 'WeeksOfMonth' (enames $t.ScheduleByMonthDayOfWeek.WeeksOfMonth)
      addv $mdw 'Months' (enames $t.ScheduleByMonthDayOfWeek.Months)
      if ($mdw.Count -gt 0) { $item['ScheduleByMonthDayOfWeek'] = $mdw }
    }

    if ($item.Count -gt 0) { $list.Add([pscustomobject]$item) }
  }
  $list.ToArray()
}

function actinfo { param($an)
  if (-not $an) { return @() }
  $list = New-Object System.Collections.Generic.List[object]
  foreach ($a in $an.ChildNodes) {
    if ($a.NodeType -ne 'Element') { continue }
    $item = @{}
    addv $item 'Type' $a.LocalName
    addv $item 'Id' ([string]$a.Id)
    addv $item 'Command' ([string]$a.Command)
    addv $item 'Arguments' ([string]$a.Arguments)
    addv $item 'WorkingDirectory' ([string]$a.WorkingDirectory)
    addv $item 'ClassId' ([string]$a.ClassId)
    addv $item 'Data' ([string]$a.Data)
    addv $item 'To' ([string]$a.To)
    addv $item 'From' ([string]$a.From)
    addv $item 'Subject' ([string]$a.Subject)
    addv $item 'Body' ([string]$a.Body)
    addv $item 'Server' ([string]$a.Server)
    addv $item 'Header' ([string]$a.Header)
    addv $item 'Attachment' ([string]$a.Attachment)
    if ($item.Count -gt 0) { $list.Add([pscustomobject]$item) }
  }
  $list.ToArray()
}

$tasks = Get-ScheduledTask
$rows = New-Object System.Collections.Generic.List[object]
foreach ($t in $tasks) {
  $xt = $null
  $x = $null
  try {
    $xt = Export-ScheduledTask -TaskName $t.TaskName -TaskPath $t.TaskPath
    $x = [xml]$xt
  } catch {}

  $reg = if ($x) { $x.Task.RegistrationInfo } else { $null }
  $raw = if ($reg) { $reg.Description } else { $t.Description }

  $rows.Add([pscustomobject]@{
    Name = $t.TaskName
    Path = $t.TaskPath
    Description = (tdesc $raw)
    RegistrationInfo = if ($reg) {
      $r = @{}
      addv $r 'Author' ([string]$reg.Author)
      addv $r 'URI' ([string]$reg.URI)
      addv $r 'Date' ([string]$reg.Date)
      if ($r.Count -gt 0) { [pscustomobject]$r } else { $null }
    } else { $null }
    Principals = if ($x) { prinfo $x.Task.Principals } else { @() }
    Settings = if ($x) { setinfo $x.Task.Settings } else { $null }
    Triggers = if ($x) { triginfo $x.Task.Triggers } else { @() }
    Actions = if ($x) { actinfo $x.Task.Actions } else { @() }
  })
}

$rows.ToArray() | ConvertTo-Json -Depth 20 | sc ".\scheduled-tasks.json"
