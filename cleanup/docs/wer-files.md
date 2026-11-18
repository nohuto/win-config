# WER Files

Windows Error Reporting (WER) queues crash dumps and report metadata under `%PROGRAMDATA%\Microsoft\Windows\WER` (system) and `%LOCALAPPDATA%\Microsoft\Windows\WER` (per user). Clearing the queue removes pending uploads and archived `.wer` files.

Paths removed:
```c
%PROGRAMDATA%\Microsoft\Windows\WER\*
%LOCALAPPDATA%\Microsoft\Windows\WER\*
```

