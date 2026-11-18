# DNS Cache

`Get-DnsClientCache` shows the resolver cache that stores recent lookups. Flushing it via `ipconfig /flushdns` can fix stale entries after moving domains or switching VPN profiles (or if editing the hosts file).

Command used:
```cmd
ipconfig /flushdns
```

