# Disable WPAD

Only use this option if you don't need a proxy that gets discovered automatically, a manually set proxy/PAC URL keeps working.

> "*Windows uses Web Proxy Auto-Discovery protocol (WPAD) to discover Proxy Auto-Config (PAC) files from the local network. If you prefer to manage endpoints directly, you can disable WPAD.*"
>
> "*After you disable WPAD, you must manually configure all proxies. The registry key stops WPAD detection for all proxy detection calls made through the Windows HTTP Services (WinHTTP) application programming interface (API). Even with this registry key set, applications can still resolve the name "WPAD" by calling Domain Name System (DNS) directly. For example, running `nslookup WPAD` still resolves the name by using DNS.*"
>
> "*In addition to setting the registry key, WPAD should also be disabled in the Windows **Settings** UI, because third-party apps and Internet browsers may rely on these settings for Proxy Auto-Discovery.*"
>
> — Microsoft, [How to disable HTTP proxy features](https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/disable-http-proxy-auth-features#how-to-disable-wpad)


## Registry Values

```c
"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\WinHttp";
  "DisableWpad" = 0; // REG_DWORD (bool)

"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Connections";
  "DefaultConnectionSettings" = ?; // REG_BINARY, byte 8 = 0x01 direct, 0x02 proxy server, 0x04 setup script, 0x08 auto detect settings

// QuerySwpadEnabledInitOnceCallback (winhttp.dll)
"HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Wpad";
  "WpadOverride" = ?; // REG_DWORD, 1 = g_fDisableSwpad & g_fDisableIpCache, 2 = g_fDisableIpCache
```

## winhttp.dll

If `DisableWpad` is set, the service skips its WPAD setup and fails every request that only asks for auto detection:

```c
// AUTOPROXY_RPC_SERVER::Open (23H2)

v16 = InternetReadRegistryDwordKey(
        v13,
        L"DisableWpad",
        &v32,
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\WinHttp");
v18 = (HKEY)v32;
v19 = 0;
if ( v16 )
  v18 = 0LL;
v32 = (unsigned int)v18;
LOBYTE(v19) = (_DWORD)v18 != 0;
*((_DWORD *)v1 + 29) = v19; // DisableWpad != 0

if ( (unsigned int)WxIsPlatformXBox() || *((_DWORD *)v1 + 29) )
{
  if ( (qword_180114EA0 & 2) != 0 )
  {
    v25 = *((_DWORD *)v1 + 29);
    IsPlatformXBox = WxIsPlatformXBox();
    WPP_SF_ll(49LL, &WPP_c92486a5225339fb331feeb700d2ada4_Traceguids, IsPlatformXBox, v25);
  }
  *((_DWORD *)v1 + 29) = 1; // no WPAD setup
}
else
{
  AUTOPROXY_RPC_SERVER::CreateAndInitializeWpadSetting(v1);
}
```

```c
// AUTOPROXY_RPC_SERVER::GetProxyForUrlImp (23H2)

v21 = *((_DWORD *)this + 29);
if ( v21 && (*(_DWORD *)a5 & 0x40602) == 0 ) // auto detect only
{
  Reply = -2146685036; // 0x800C2F94, ERROR_WINHTTP_AUTODETECTION_FAILED (12180)
  v27 = 1790;
  goto LABEL_8;
}
```

`a5` (`_AUTOPROXY_OPTIONS`) carries the caller's `WINHTTP_AUTOPROXY_OPTIONS` flags, `0x40602` = `WINHTTP_AUTOPROXY_CONFIG_URL | WINHTTP_AUTOPROXY_ALLOW_STATIC | WINHTTP_AUTOPROXY_ALLOW_CM | WINHTTP_AUTOPROXY_NO_DIRECTACCESS`. A request with none of them (`WINHTTP_AUTOPROXY_AUTO_DETECT` via DHCP and/or DNS) fails:

```c
// winhttp.h
typedef struct _WINHTTP_AUTOPROXY_OPTIONS
{
    DWORD   dwFlags;
    DWORD   dwAutoDetectFlags;
    LPCWSTR lpszAutoConfigUrl;
    LPVOID  lpvReserved;
    DWORD   dwReserved;
    BOOL    fAutoLogonIfChallenged;
} WINHTTP_AUTOPROXY_OPTIONS, *PWINHTTP_AUTOPROXY_OPTIONS;

#define WINHTTP_AUTOPROXY_AUTO_DETECT           0x00000001
#define WINHTTP_AUTOPROXY_CONFIG_URL            0x00000002
#define WINHTTP_AUTOPROXY_HOST_KEEPCASE         0x00000004
#define WINHTTP_AUTOPROXY_HOST_LOWERCASE        0x00000008
#define WINHTTP_AUTOPROXY_ALLOW_AUTOCONFIG      0x00000100
#define WINHTTP_AUTOPROXY_ALLOW_STATIC          0x00000200
#define WINHTTP_AUTOPROXY_ALLOW_CM              0x00000400
#define WINHTTP_AUTOPROXY_USE_INTERFACE_CONFIG  0x00000800
#define WINHTTP_AUTOPROXY_RUN_INPROCESS         0x00010000
#define WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY   0x00020000
#define WINHTTP_AUTOPROXY_NO_DIRECTACCESS       0x00040000
#define WINHTTP_AUTOPROXY_NO_CACHE_CLIENT       0x00080000
#define WINHTTP_AUTOPROXY_NO_CACHE_SVC          0x00100000
#define WINHTTP_AUTOPROXY_SORT_RESULTS          0x00400000

#define WINHTTP_AUTO_DETECT_TYPE_DHCP           0x00000001
#define WINHTTP_AUTO_DETECT_TYPE_DNS_A          0x00000002
```
