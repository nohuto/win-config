# Shadow Copies

Removes all copies (volume backups). See your current shadows with:
```cmd
vssadmin list shadows /for=<ForVolumeSpec> /shadow=<ShadowID>
```

`<ForVolumeSpec>` -> Volume
`<ShadowID>` -> Shadow copy specified by ShadowID

Command used:
```cmd
vssadmin delete shadows /all /quiet
```

