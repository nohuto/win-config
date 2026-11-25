# Disable LLSE

Turns off the System log entries an Intel NIC writes when its link goes up/down, nothing more.

> *This setting is used to enable/disable the logging of link state changes. If enabled, a link-up change event or a link-down change event generates a message that is displayed in the system event logger. This message contains the link’s speed and duplex. Administrators view the event message from the system event log.*
>
> *The following events are logged:*
> - *The link is up.*
> - *The link is down.*
> - *Mismatch in duplex.*
> - *Spanning Tree Protocol detected.*
>
> — Intel, [Log Link State Event](https://edc.intel.com/content/www/us/en/design/products/ethernet/adapters-and-devices-user-guide/log-link-state-event/)

## Registry Values

Note that `LogLinkStateEvent` is an Intel keyword, and each driver may have different defaults, examples:

| Value | Default | Meaning |
| --- | --- | --- |
| `51` | `net1ic64.inf` (I219), `net2ic68.inf` (I225/I226) | Enabled |
| `19` | `net1yx64.inf`, `nete1e3e.inf` | Enabled |
| `16` | | Disabled |

The I225/I226 driver `e2fn.sys` (2.x) has no INF entry for either value and reads both as on/off switches from its own keyword table. `LogLinkStateEvent` defaults to `1`, `LogWolEvent` (wake pattern events in Event Viewer) to `0`. `16` doesn't turn it off there: on my I225-V with `e2fn.sys` 2.1.5.7 and `LogLinkStateEvent` = `16`, the System log still shows the link events 27 and 32 (`e2fnexpress`). That's why `Disable (Intel I225/I226 e2fn driver)` writes `0` to both (`LogWolEvent` = `0` equals the e2fn default, whether `0` stops the link events isn't tested yet), `Disable (other Intel drivers)` writes `16`, and `Default` deletes both so each driver uses its own default.

```c
// sub_14007E540 (e2fn.sys 2.1.5.7)

v47 = L"LogLinkStateEvent";
v51 = L"LogWolEvent";

v46 = 2359330;
LOBYTE(v48) = 1; // LogLinkStateEvent default
v50 = 1572886;
LOBYTE(v52) = 0; // LogWolEvent default
```

`framework::WolPatternsEventViewerLogger::Initialize` keeps the `LogWolEvent` result as the logger switch:

```c
// framework::WolPatternsEventViewerLogger::Initialize

sub_1400011A8(&v11, L"LogWolEvent", 11LL);
sub_1400A27D4(&v9, a1 + 112);
v5 = sub_14003E2F0(v9, &v11, v9 + 16);
v6 = v10;
*(_BYTE *)(a1 + 696) = v5; // logger on/off
```

