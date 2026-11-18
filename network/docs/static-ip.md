# Static IP

Reads the active adapter's IPv4 settings from `netsh int ip show config` and applies them directly via registry. A static IP is useful for devices that must keep the same address (NAS, game servers, port forwarding, monitoring agents) so clients and firewall rules always target a stable IP. **Static IP requires a manual DNS server**. Use the `Encrypted DNS` option above to set `NameServer` for the same adapter.

### Terms Meaning

- `IP Address` is the device's local IPv4 on your LAN
- `Default Gateway` is your router IP used to reach other networks (internet)
- `Subnet Mask` defines which IPs are local (same subnet) vs routed via the gateway
- [`DHCP`](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol) (Dynamic Host Configuration Protocol) registers and updates IP address, subnet mask, gateway, and DNS

