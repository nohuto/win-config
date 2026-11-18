# Hash Generator

> "*The `Get-FileHash` cmdlet computes the hash value for a file by using a specified hash algorithm. A hash value is a unique value that corresponds to the content of the file. Rather than identifying the contents of a file by its file name, extension, or other designation, a hash assigns a unique value to the contents of a file. File names and extensions can be changed without altering the content of the file, and without changing the hash value. Similarly, the file's content can be changed without changing the name or extension. However, changing even a single character in the contents of a file changes the hash value of the file.*
>
> *The purpose of hash values is to provide a cryptographically-secure way to verify that the contents of a file have not been changed. While some hash algorithms, including MD5 and SHA1, are no longer considered secure against attack, the goal of a secure hash algorithm is to render it impossible to change the contents of a file either by accident, or by malicious or unauthorized attempt and maintain the same hash value. You can also use hash values to determine if two different files have exactly the same content. If the hash values of two files are identical, the contents of the files are also identical.*"
>
> — Microsoft, [Get-FileHash](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.utility/get-filehash?view=powershell-7.5)

![](https://github.com/nohuto/win-config/blob/main/misc/images/hashgen.png?raw=true)

## Algorithms

`Get-FileHash -Algorithm` accepts (the script uses the built in .NET hash implementations `System.Security.Cryptography`):

- [`MD5`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.md5?view=net-9.0) (`128` Bits)
- [`SHA1`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha1?view=net-9.0) (`160` Bits)
- [`SHA256`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha256?view=net-9.0) (`256` Bits)
- [`SHA384`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha384?view=net-9.0) (`384` Bits)
- [`SHA512`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.sha512?view=net-9.0) (`512` Bits)
- [`MACTripleDES`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.mactripledes?view=net-9.0)
- [`RIPEMD160`](https://learn.microsoft.com/en-us/dotnet/api/system.security.cryptography.ripemd160?view=net-9.0)

## Hash Examples

The computed hash depends on the file content. With the same algorithm, identical inputs (including empty files) have identical hashes.

### Scenario 1 (no content)

```powershell
PS C:\Users\Nohuxi> Get-Content -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse0.txt' -Raw
PS C:\Users\Nohuxi> # No output, since empty

PS C:\Users\Nohuxi> 'MD5','SHA1','SHA256','SHA384','SHA512' | % { '{0}: {1}' -f $_,(Get-FileHash -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse0.txt' -Algorithm $_).Hash }
MD5: D41D8CD98F00B204E9800998ECF8427E
SHA1: DA39A3EE5E6B4B0D3255BFEF95601890AFD80709
SHA256: E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855
SHA384: 38B060A751AC96384CD9327EB1B1E36A21FDB71114BE07434C0CC7BF63F6E1DA274EDEBFE76F65FBD51AD2F14898B95B
SHA512: CF83E1357EEFB8BDF1542850D66D8007D620E4050B5715DC83F4A921D36CE9CE47D0D13C5D85F2B0FF8318D2877EEC2F63B931BD47417A81A538327AF927DA3E
```

###  Scenario 2 (content)

```powershell
PS C:\Users\Nohuxi> Get-Content -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse1.txt' -Raw
1 # Content
PS C:\Users\Nohuxi>

PS C:\Users\Nohuxi> 'MD5','SHA1','SHA256','SHA384','SHA512' | % { '{0}: {1}' -f $_,(Get-FileHash -LiteralPath 'C:\Users\Nohuxi\Desktop\Noverse1.txt' -Algorithm $_).Hash }
MD5: C4CA4238A0B923820DCC509A6F75849B
SHA1: 356A192B7913B04C54574D18C28D46E6395428AB
SHA256: 6B86B273FF34FCE19D6B804EFF5A3F5747ADA4EAA22F1D49C01E52DDB7875B4B
SHA384: 47F05D367B0C32E438FB63E6CF4A5F35C2AA2F90DC7543F8A41A0F95CE8A40A313AB5CF36134A2068C4C969CB50DB776
SHA512: 4DFF4EA340F0A823F15D3F4F01AB62EAE0E5DA579CCB851F8DB9DFE84C58B2B37B89903A740E1EE172DA793A6E79D560E5F7F9BD058A12A280433ED6FA46510A
```

As you can see, adding a `1` to the file content has completely changed the hash values. You can try this yourself by editing the paths.

```powershell
MD5("") 
0x d41d8cd98f00b204e9800998ecf8427e
SHA1("")
0x da39a3ee5e6b4b0d3255bfef95601890afd80709
SHA256("")
0x e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
SHA384("")
0x 38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b
SHA512("")
0x cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e
```

## Installation

If using win-config, then the toggle automates the (un)installation.

- [`HashGen.ps1`](https://github.com/nohuto/win-config/blob/main/misc/assets/scripts/HashGen.ps1) accepts an optional `-Algorithm` parameter (`All`, `MD5`, `SHA1`, `SHA256`, `SHA384`, `SHA512`, `MACTripleDES`, `RIPEMD160`). By default it runs every available algorithm, but you can target a specific hash when invoking it manually. 
- [`Add-CM.ps1`](https://github.com/nohuto/win-config/blob/main/misc/assets/scripts/Add-CM.ps1) will add a `Hashes` cascaded option to the context menu of any file/folder (if selecting a folder all files within the folder and every subfolder will get used). `HashGen.ps1` gets used from your `Downloads` folder if present, otherwise `Add-CM.ps1` automatically downloads the latest copy from GitHub. `Add-CM.ps1` copies `HashGen.ps1` into `%LOCALAPPDATA%\Noverse` and adds a *Hashes* entry for files and folders.

## Uninstallation

Remove the content menu entry and `hashGen` with:
```powershell
Remove-Item -LiteralPath "HKCU:\Software\Classes\*\shell\Hashes" -Recurse -Force
Remove-Item -LiteralPath "HKCU:\Software\Classes\Directory\shell\Hashes" -Recurse -Force
Remove-Item -LiteralPath "HKCU:\Software\Classes\hashGen.ContextMenu" -Recurse -Force
#Remove-Item -LiteralPath "HKCU:\Software\Classes\*\shell\NV-Hash" -Recurse -Force  # old entry
#Remove-Item -LiteralPath "HKCU:\Software\Classes\Directory\shell\NV-Hash" -Recurse -Force  # old entry
Remove-Item -Path "$env:LOCALAPPDATA\Noverse\HashGen.ps1" -Force
```
