Add-Type -AssemblyName System.Windows.Forms, System.Drawing
Add-Type -TypeDefinition 'using System;using System.Runtime.InteropServices;public class WinAPI{[DllImport("user32.dll")]public static extern bool ShowWindow(IntPtr hWnd,int nCmdShow);}'
if (!(Test-Path "$env:temp\Noverse.ico")) {iwr -uri "https://github.com/5Noxi/5Noxi/releases/download/Logo/Noverse.ico" -out "$env:temp\Noverse.ico"}
$gray = [Drawing.Color]::FromArgb(28, 28, 28)
$white = [Drawing.Color]::White

# Authored by Nohuxi
function nvreglog {
    param ([string]$title,[string]$message,[string]$type = "info")
    $form = [Windows.Forms.Form]@{
        Text = $title
        Size = [Drawing.Size]::new(320, 125)
        StartPosition = 'CenterParent'
        BackColor = $gray
        FormBorderStyle = 'FixedDialog'
        MaximizeBox = $false
        MinimizeBox = $false
        TopMost = $true
        Icon = [System.Drawing.Icon]::ExtractAssociatedIcon("$env:temp\Noverse.ico")
    }

    $label = [Windows.Forms.Label]@{
        Text = $message
        ForeColor = 'White'
        Font = [Drawing.Font]::new("Segoe UI", 9)
        AutoSize = $false
        TextAlign = 'MiddleCenter'
        Size = [Drawing.Size]::new(280, 35)
        Location = [Drawing.Point]::new(20, 10)
    }
    $form.Controls.Add($label)

    $ok = [Windows.Forms.Button]@{
        Text = "OK"
        Size = [Drawing.Size]::new(80, 25)
        Location = [Drawing.Point]::new(115, 55)
        BackColor = if ($type -eq 'error') { [Drawing.Color]::IndianRed } else { [Drawing.Color]::CornflowerBlue }
        ForeColor = 'White'
        FlatStyle = 'Flat'
    }
    $ok.Add_Click({ $form.Close() })
    $form.Controls.Add($ok)
    $form.ShowDialog()
}

$nvmain = [Windows.Forms.Form] @{
    Text = "Desktop Icon Spacing"
    Size = [Drawing.Size]::new(470, 240)
    StartPosition = 'CenterScreen'
    BackColor = $gray
    Icon = [Drawing.Icon]::ExtractAssociatedIcon("$env:temp\Noverse.ico")
}

$labelh = [Windows.Forms.Label] @{
    Text = "Horizontal spacing"
    Location = [Drawing.Point]::new(10, 20)
    ForeColor = $white
    BackColor = $gray
}
$nvmain.Controls.Add($labelh)

$labelv = [Windows.Forms.Label] @{
    Text = "Vertical spacing"
    Location = [Drawing.Point]::new(10, 90)
    ForeColor = $white
    BackColor = $gray
}
$nvmain.Controls.Add($labelv)

try {$regh = Get-ItemPropertyValue -Path "HKCU:\Control Panel\Desktop\WindowMetrics" -Name "IconSpacing";$valh = [int]([math]::Round($regh / -15))} catch {$valh = 75}
try {$regv = Get-ItemPropertyValue -Path "HKCU:\Control Panel\Desktop\WindowMetrics" -Name "IconVerticalSpacing";$valv = [int]([math]::Round($regv / -15))} catch {$valv = 75}

$slidho = [Windows.Forms.TrackBar] @{
    Minimum = 32
    Maximum = 182
    TickFrequency = 10
    Value = $valh
    SmallChange = 1
    LargeChange = 5
    Location = [Drawing.Point]::new(10, 40)
    Size = [Drawing.Size]::new(300, 30)
    BackColor = $gray
}
$nvmain.Controls.Add($slidho)

$slidvert = [Windows.Forms.TrackBar] @{
    Minimum = 32
    Maximum = 182
    TickFrequency = 10
    Value = $valv
    SmallChange = 1
    LargeChange = 5
    Location = [Drawing.Point]::new(10, 110)
    Size = [Drawing.Size]::new(300, 30)
    BackColor = $gray
}
$nvmain.Controls.Add($slidvert)

$numho = [Windows.Forms.NumericUpDown] @{
    Minimum    = 32
    Maximum    = 182
    Location   = [Drawing.Point]::new(320, 40)
    BackColor  = $gray
    ForeColor  = $white
}
$numho.Value = [decimal][math]::Max($numho.Minimum, [math]::Min($numho.Maximum, $valh))
$nvmain.Controls.Add($numho)

$numvert = [Windows.Forms.NumericUpDown] @{
    Minimum    = 32
    Maximum    = 182
    Location   = [Drawing.Point]::new(320, 110)
    BackColor  = $gray
    ForeColor  = $white
}
$numvert.Value = [decimal][math]::Max($numvert.Minimum, [math]::Min($numvert.Maximum, $valv))
$nvmain.Controls.Add($numvert)

$slidho.Add_ValueChanged({ $numho.Value = $slidho.Value })
$slidvert.Add_ValueChanged({ $numvert.Value = $slidvert.Value })
$numho.Add_ValueChanged({ $slidho.Value = [int]$numho.Value })
$numvert.Add_ValueChanged({ $slidvert.Value = [int]$numvert.Value })

$apply = [Windows.Forms.Button] @{
    Text = "Apply"
    Location = [Drawing.Point]::new(130, 160)
    BackColor = [Drawing.Color]::FromArgb(50, 50, 50)
    ForeColor = $white
    FlatStyle = 'Flat'
    Size = [Drawing.Size]::new(80, 25)
    Font = $inputf
}
$apply.FlatAppearance.BorderColor = [Drawing.Color]::Gray
$apply.FlatAppearance.BorderSize = 1
$apply.Add_Click({
        $hval = -15 * $slidho.Value
        $vval = -15 * $slidvert.Value
        sp -Path "HKCU:\Control Panel\Desktop\WindowMetrics" -Name "IconSpacing" -Value ([string]$hval) -Force
        sp -Path "HKCU:\Control Panel\Desktop\WindowMetrics" -Name "IconVerticalSpacing" -Value ([string]$vval) -Force
        sp -Path "HKCU:\Control Panel\Desktop\WindowMetrics" -Name "IconTitleWrap" -Value 0 -Force
        nvreglog "Changed" "Added IconSpacing '$hval'`nAdded 'IconVerticalSpacing '$vval'"
})
$nvmain.Controls.Add($apply)

$signout = [Windows.Forms.Button] @{
    Text = "Sign Out"
    Location = [Drawing.Point]::new(230, 160)
    BackColor = [Drawing.Color]::FromArgb(50, 50, 50)
    ForeColor = $white
    FlatStyle = 'Flat'
    Size = [Drawing.Size]::new(80, 25)
    Font = $inputf
}
$signout.FlatAppearance.BorderColor = [Drawing.Color]::Gray
$signout.FlatAppearance.BorderSize = 1
$signout.Add_Click({shutdown.exe /l})
$nvmain.Controls.Add($signout)

[WinAPI]::ShowWindow((gps -Id $PID).MainWindowHandle, 0)
$nvmain.Add_FormClosed({kill -Id $PID})
[Windows.Forms.Application]::Run($nvmain)