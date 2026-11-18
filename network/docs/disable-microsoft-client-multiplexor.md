# Disable Microsoft Client/Multiplexor

Disables the Client for Microsoft Networks (`ms_msclient`) and the Microsoft Network Adapter Multiplexor Protocol (`ms_implat`) bindings on all adapters. This blocks SMB client access and disables NIC teaming.

SMB client I/O is handled by the LANMan Redirector (client-side remote FSD) which translates file I/O into SMB commands, while the server side uses `Srv2.sys`. Disabling `ms_msclient` prevents the redirector from binding to the adapter, so SMB client access is effectively disabled regardless of SMB version. This is broader than the SMBv1 toggle (which only removes the legacy protocol).

