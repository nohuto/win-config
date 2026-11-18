# Disable LLSE

This setting is used to enable/disable the logging of link state changes. If enabled, a link-up change event or a link-down change event generates a message that is displayed in the system event logger. This message contains the link's speed and duplex. Administrators view the event message from the system event log.

The following events are logged:  
- The link is up. (`LINK_UP_CHANGE`)
- The link is down. (`LINK_DOWN_CHANGE`)
- Mismatch in duplex. (`LINK_DUPLEX_MISMATCH`)
- Spanning Tree Protocol detected.

## Setup Information

```c
,Log Link State Event
HKR,Ndi\Params\LogLinkStateEvent,                       ParamDesc,              0, %LogLinkState%
HKR,Ndi\Params\LogLinkStateEvent,                       Type,                   0, "enum"
HKR,Ndi\Params\LogLinkStateEvent,                       Default,                0, "51"
HKR,Ndi\Params\LogLinkStateEvent\Enum,                  "51",                   0, %Enabled%
HKR,Ndi\Params\LogLinkStateEvent\Enum,                  "16",                   0, %Disabled%
```

---

Miscellaenous notes:
```c
"LogWolEvent" = 16  // ?
```

