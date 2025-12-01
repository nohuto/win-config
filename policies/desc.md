# Windows Policies

This section is based on my [admx-parser](https://github.com/5Noxi/admx-parser) project. You can get the whole parsed ADMX content via

```powershell
python admx-parser.py [FLAGS]
```

### CLI Flags

`-d, --definitions PATH` - PolicyDefinitions directory - Default: `C:\Windows\PolicyDefinitions`
`-l, --language LANG` - Include a language folder (repeatable) - Default: Auto-detected + `en-US`
`-i, --ignore NAME` - Ignore an ADMX base name (repeatable) - Default: None
`--class {Machine,User}` - Restrict to policy class (repeatable) - Default: All
`--category TEXT` - Filter by category substring - Default: None
`--policy TEXT` - Filter by policy/display name substring - Default: None
`--include-obsolete` - Include obsolete/deprecated policies - Default: Off
`--format {json,yaml}` - Output format - Default: `json`
`--compress` - Write minified JSON (ignored for YAML) - Default: Pretty
`--output PATH` - Custom destination file - Default: `Policies.json` / `Policies.yaml` (in current dir)
`-h, --help` - Shows flags from above - Default: /

### Examples

```c
// Default (pretty JSON)
python admx-parser.py

// YAML output, ignore inetres and WindowsUpdate ADMX files
python admx-parser.py --format yaml --ignore inetres --ignore WindowsUpdate

// Machine-only policies under the Edge category, compressed JSON
python admx-parser.py --class Machine --category Edge --compress
```