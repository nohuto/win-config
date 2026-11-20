# WinConfig

You can find the documentation on my website (this repo is the source):

- https://noverse.dev/docs/win-config

## Product

See details about the tool here:

- https://noverse.dev/product

### Verify Binaries

All releases have a detached GPG sig, import the [public key](https://pgp.noverse.dev) and verify the installer next to its sig:

```powershell
curl.exe -fsSL https://pgp.noverse.dev -o public.asc
gpg --import public.asc

gpg --verify winconfig-setup-<version>.exe.sig winconfig-setup-<version>.exe
```

It must show `Good signature from "nohuto <contact@noverse.dev>"`, made by the signing subkey `FF65 399D 1B28 95F6 CC34  BE79 1853 081F E103 04A2`.
