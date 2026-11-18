# Static IP

Useful for devices that must keep the same address (NAS, game servers, port forwarding, monitoring agents) so clients and firewall rules always target a stable IP. DNS servers you already set yourself are kept, otherwise the leases DNS servers become static ones. Turning it off switches the address and gateway back to DHCP (router may set a different address then).

### Terms Meaning

- `IP Address` is the device's local IPv4 on your LAN
- `Default Gateway` is your router IP used to reach other networks (internet)
- `Subnet Mask` defines which IPs are local (same subnet) vs routed via the gateway
- [`DHCP`](https://learn.microsoft.com/en-us/previous-versions/windows/desktop/dhcp/about-dynamic-host-configuration-protocol) (Dynamic Host Configuration Protocol) registers and updates IP address, subnet mask, gateway, and DNS

