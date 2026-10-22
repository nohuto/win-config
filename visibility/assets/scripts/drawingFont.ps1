Add-Type -AssemblyName System.Windows.Forms, System.Drawing
$nvmain = [Windows.Forms.Form] @{
    Text = 'NV Fonts'
    Size = [Drawing.Size]::new(1380, 1130)
    BackColor = [Drawing.Color]::FromArgb(30, 30, 30)
    AutoScroll = $true
}
$x = @(10, 360, 710, 1060)
$y = @(10, 10, 10, 10)
$fonts = [Drawing.FontFamily]::Families
for ($i = 0; $i -lt $fonts.Count; $i++) {
    $col = $i % 4
    try {
        $font = [Drawing.Font]::new($fonts[$i].Name, 11)
        $label = [Windows.Forms.Label] @{
            Text = "Sample - $($fonts[$i].Name)"
            Font = $font
            ForeColor = [Drawing.Color]::White
            AutoSize = $true
            Location = [Drawing.Point]::new($x[$col], $y[$col])
        }
        $nvmain.Controls.Add($label)
        $y[$col] += $label.Height+8
    } catch {}
}
[Windows.Forms.Application]::Run($nvmain)