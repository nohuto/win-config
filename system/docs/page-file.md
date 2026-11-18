# Page File

Will be updated soon, date of commit `04.07.2026`.

## Suboption

### Clear Page File on Shutdown

Paging files can contain fragments of process or kernel data, enabling the option mitigates offline data exposure at the cost of longer shutdowns.

> "*This security setting determines whether the virtual memory pagefile is cleared when the system is shut down.*
>
> *Virtual memory support uses a system pagefile to swap pages of memory to disk when they are not used. On a running system, this pagefile is opened exclusively by the operating system, and it is well protected. However, systems that are configured to allow booting to other operating systems might have to make sure that the system pagefile is wiped clean when this system shuts down. This ensures that sensitive information from process memory that might go into the pagefile is not available to an unauthorized user who manages to directly access the pagefile.*
>
> *When this policy is enabled, it causes the system pagefile to be cleared upon clean shutdown. If you enable this security option, the hibernation file (hiberfil.sys) is also zeroed out when hibernation is disabled.*"

