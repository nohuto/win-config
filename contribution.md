# Contribution

`Option Name` (`json` examples) must be the same as the `.md` title.

### Overview
| Context | Actions |
| ------- | ------- |
| `COMMANDS` | `run_powershell`, `delete_path`, `create_path`, `scheduled_task`, `tcp_congestion`, `netbind`, `optional_feature`, `restart_explorer`, `bcdedit`, `registry_pattern`, `mmagent`, `nvidia_key`, `ethernet_key` |
| Registry hives (`HKCU\`, `HKLM\`...) | Direct value set (`Type`, `Data`, `OnlyExisting`, `Elevated`), `deletevalue` |

### Actions & Requirements
| Action | Required / optional arguments |
| ------ | ------ |
| `run_powershell`   | Required: `Command` - Optional: `Elevated` |
| `delete_path`      | Required: `Paths` (array or string) - Optional: `Recurse` (use %ENV%, not $env:ENV here) |
| `create_path`      | Use one: `Path` or `Paths` (array) - Optional: `File` (bool) to create a file instead of directories |
| `scheduled_task`   | Use one: `TaskName` or `TaskNames` (array) - Required: `Operation` (`run`, `stop`, `enable`, `disable`, `delete`) - Optional: `Elevated` |
| `tcp_congestion`   | Required: `Templates` (string or array), `Provider` (or `Value`) |
| `netbind`          | Required: `Components` (array or string) - Required: `State` (`enable` \| `disable`) |
| `optional_feature` | Required: `Features` (array or string) - Required: `State` (`enable` \| `disable`) - Optional: `Arguments` (array or string), `Elevated` |
| `restart_explorer` | (no arguments) |
| `bcdedit`          | Required: `Name` - One of: `Value` or `Delete`/`Remove` (bool) |
| `registry_pattern` | Required: `Pattern`, `Operations` (object or array with `Value`, optional `SubKey`, `Type`, `Data`, `OnlyExisting`, `Operation`) - Optional: `Exclude` |
| `mmagent`          | Required: `Name`, desired state via one of `Enabled`/`Enable`/`State` (bool) - Optional: `Elevated` |
| `nvidia_key`       | Required: `Values` -> map of valueName -> `{ Type, Data }` (or `{ Action: "deletevalue" }`) - Optional: `SubKey` for a relative subkey |
| `ethernet_key`     | Required: `Values` -> map of valueName -> `{ Type, Data }` (or `{ Action: "deletevalue" }`) - Optional: `SubKey`, `NetIDPath` template (must contain the literal `{NetID}` placeholder) to target other hives |

### Buttons
| Key | Purpose |
| ------ | ------ |
| `__control` | `{ "type": "button", "label": "name" }` or dropdowns via `{ "type": "dropdown", "fallback": "...", "options": [...] }` |

### Examples
```json
{
  "Option Name - Direct Writes (single key/values)": {
    "apply": {
      "HKCU\\Software\\Noverse": {
        "Enabled": { "Type": "REG_DWORD", "Data": 1 },
        "Profile": { "Type": "REG_SZ", "Data": "stable" },
        "Blob": { "Type": "REG_BINARY", "Data": [222, 173, 190, 239] }
      }
    },
    "revert": {
      "HKCU\\Software\\Noverse": {
        "Enabled": { "Action": "deletevalue" },
        "Profile": { "Action": "deletevalue" },
        "Blob": { "Action": "deletevalue" }
      }
    }
  },
  "Option Name - Default Value + Create/Delete Key": {
    "apply": {
      "HKCU\\Software\\Noverse": {
        "": { "Type": "REG_SZ", "Data": "DefaultDisplayName" },
        "Version": { "Type": "REG_SZ", "Data": "1.0.0" }
      },
      "COMMANDS": {
        "EnsureCacheFolder": {
          "Action": "create_path",
          "Paths": "%PROGRAMDATA%\\Noverse\\Cache"
        }
      }
    },
    "revert": {
      "HKCU\\Software\\Noverse": {
        "Action": "delete_path",
        "Paths": "HKCU\\Software\\Noverse",
        "Recurse": true
      }
    }
  },
  "Option Name - Only update if value exists": {
    "apply": {
      "HKCU\\Software\\Noverse": {
        "ExistingSwitch": { "Type": "REG_DWORD", "Data": 0, "OnlyExisting": true }
      }
    },
    "revert": {
      "HKCU\\Software\\Noverse": {
        "ExistingSwitch": { "Action": "deletevalue" }
      }
    }
  },
  "Option Name - Elevated registry write": {
    "apply": {
      "HKLM\\SYSTEM\\CurrentControlSet\\Services\\WdiServiceHost": {
        "Start": { "Type": "REG_DWORD", "Data": 4, "OnlyExisting": true, "Elevated": true }
      }
    },
    "revert": {
      "HKLM\\SYSTEM\\CurrentControlSet\\Services\\WdiServiceHost": {
        "Start": { "Type": "REG_DWORD", "Data": 3, "Elevated": true }
      }
    }
  },
  "Option Name - Edits across any path containing 'Noverse' (wildcards)": {
    "apply": {
      "COMMANDS": {
        "TuneAllNoverseProfiles": { // Define any name
          "Action": "registry_pattern",
          "Pattern": "HKCU\\Software\\**Noverse**\\**\\Profiles\\*",
          "Operations": [
            { "SubKey": "Settings1", "Value": "Enabled", "Type": "REG_DWORD", "Data": 1 },
            { "SubKey": "Settings2", "Value": "Channel", "Type": "REG_SZ", "Data": "Test" }
          ]
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "UntuneAllNoverseProfiles": {
          "Action": "registry_pattern",
          "Pattern": "HKCU\\Software\\**Noverse**\\**\\Profiles\\*",
          "Operations": [
            { "SubKey": "Settings1", "Value": "Enabled", "Operation": "deletevalue" },
            { "SubKey": "Settings2", "Value": "Channel", "Operation": "deletevalue" }
          ]
        }
      }
    }
  },
  "Option Name - Target a service/device style subtree with exclusions": {
    "apply": {
      "COMMANDS": {
        "SetNoverseAdvanced": {
          "Action": "registry_pattern",
          "Pattern": "HKLM\\SYSTEM\\*ControlSet*\\Services\\**Noverse**\\**",
          "Exclude": ["*\\KeyName"],
          "Operations": [
            { "Value": "Throttle", "Type": "REG_DWORD", "Data": 0 },
            { "SubKey": "Parameters", "Value": "TraceLevel", "Operation": "deletevalue" }
          ]
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "RevertNoverseAdvanced": {
          "Action": "registry_pattern",
          "Pattern": "HKLM\\SYSTEM\\*ControlSet*\\Services\\**Noverse**\\**",
          "Operations": [
            { "Value": "Throttle", "Operation": "deletevalue" }
          ]
        }
      }
    }
  },
  "Option Name - PowerShell Command": {
    "apply": {
      "COMMANDS": {
        "WriteViaPS": {
          "Action": "run_powershell",
          "Elevated": true, // if set the command will get executed with MinSudo
          "Command": "New-Item -Path 'HKCU:\\Software\\Noverse' -Force | Out-Null; New-Item -Path 'HKCU:\\Software\\Noverse' -Force | Out-Null; New-ItemProperty -Path 'HKCU:\\Software\\Noverse' -Name 'Computed' -PropertyType String -Value ([string](Get-Date -Format o)) -Force | Out-Null"
        }
      }
    },
    "revert": {
      "HKCU\\Software\\Noverse": {
        "Computed": { "Action": "deletevalue" }
      }
    }
  },
  "Option Name - Button (no revert)": {
    "__control": { "type": "button", "label": "Open" },
    "COMMANDS": {
      "RemoveWindowsOld": {
        "Action": "run_powershell",
        "Command": "Start-Process powershell -ArgumentList '-NoProfile -Command \"iwr -UseBasicParsing -Uri https://raw.githubusercontent.com/5Noxi/win-config/refs/heads/main/visibility/assets/Icon-Spacing.ps1 | iex\"'"
      }
    }
  },
  "Option Name - Delete Paths (multi)": {
    "__control": { "type": "button", "label": "Delete" },
    "COMMANDS": {
      "DeleteNoversePaths": {
        "Action": "delete_path",
        "Recurse": true,
        "Paths": [
          "HKCU\\Software\\Noverse\\Nohuxi",
          "%PROGRAMDATA%\\Noverse\\Cache", // don't use $env:
          "%LOCALAPPDATA%\\Noverse\\Temp"
        ]
      }
    }
  },
  "Option Name - Dropdown to toggle TCP congestion": {
    "apply": {
      "__control": {
        "type": "dropdown",
        "fallback": "Select",
        "options": [
          {
            "label": "BBR2",
            "config": {
              "COMMANDS": {
                "SetTCP_BBR2": {
                  "Action": "tcp_congestion",
                  "Templates": [ "Internet", "Datacenter" ],
                  "Provider": "bbr2"
                }
              }
            }
          },
          {
            "label": "CUBIC",
            "config": {
              "COMMANDS": {
                "SetTCP_CUBIC": {
                  "Action": "tcp_congestion",
                  "Templates": [ "Internet", "Datacenter" ],
                  "Provider": "cubic"
                }
              }
            }
          }
        ]
      }
    }
  },
  "Option Name - Scheduled Tasks": {
    "apply": {
      "COMMANDS": {
        "DisableNoverseTasks": {
          "Action": "scheduled_task",
          "TaskNames": [
            "\\Noverse\\Telemetry*",
            "\\Microsoft\\Windows\\Noverse\\Update"
          ],
          "Operation": "disable"
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "EnableNoverseTasks": {
          "Action": "scheduled_task",
          "TaskNames": [
            "\\Noverse\\Telemetry*",
            "\\Microsoft\\Windows\\Noverse\\Update"
          ],
          "Operation": "enable"
        }
      }
    }
  },
  "Option Name - Scheduled Tasks (run/stop/delete)": {
    "apply": {
      "COMMANDS": {
        "RunOnce": { 
          "Action": "scheduled_task", 
          "TaskName": "\\Noverse\\Telemetry Daily", 
          "Operation": "run" 
        },
        "StopNow": { 
          "Action": "scheduled_task", 
          "TaskName": "\\Noverse\\Telemetry Daily", 
          "Operation": "stop" 
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "DeleteTask": { 
          "Action": "scheduled_task", 
          "TaskName": "\\Noverse\\Telemetry Daily", 
          "Operation": "delete" 
        }
      }
    }
  },
  "Option Name - TCP Congestion": {
    "apply": {
      "COMMANDS": {
        "SetTCPProvider_BBR2": {
          "Action": "tcp_congestion",
          "Templates": [
            "Internet",
            "InternetCustom",
            "Compat",
            "Datacenter",
            "DatacenterCustom"
          ],
          "Provider": "bbr2"
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "SetTCPProvider_CUBIC": {
          "Action": "tcp_congestion",
          "Templates": [
            "Internet",
            "InternetCustom",
            "Compat",
            "Datacenter",
            "DatacenterCustom"
          ],
          "Provider": "cubic"
        }
      }
    }
  },
  "Option Name - Netbind": {
    "apply": {
      "COMMANDS": {
        "DisableBindings": {
          "Action": "netbind",
          "Components": ["ms_tcpip6", "ms_lltdio"],
          "State": "disable"
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "EnableBindings": {
          "Action": "netbind",
          "Components": ["ms_tcpip6", "ms_lltdio"],
          "State": "enable"
        }
      }
    }
  },
  "Option Name - Optional Features": {
    "apply": {
      "COMMANDS": {
        "DisableOptionalFeatures": {
          "Action": "optional_feature",
          "Arguments": [ "/NoRestart", "/Quiet" ],
          "Features": [
            "TelnetClient",
            "SMB1Protocol"
          ],
          "State": "disable"
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "EnableOptionalFeatures": {
          "Action": "optional_feature",
          "Features": [
            "TelnetClient",
            "SMB1Protocol"
          ],
          "State": "enable"
        }
      }
    }
  },
  "Option Name - Restart Explorer": {
    "apply": {
      "HKCU\\Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}\\InprocServer32": {
        "": { "Type": "REG_SZ", "Data": "" } 
      },
      "COMMANDS": { "RestartExplorer": { "Action": "restart_explorer" } }
    },
    "revert": {
      "HKCU\\Software\\Classes\\CLSID\\{86ca1aa0-34aa-4e8b-a509-50c905bae2a2}": { 
        "Action": "delete_path", "Recurse": true
      },
      "COMMANDS": { "RestartExplorer": { "Action": "restart_explorer" } }
    }
  },
  "Option Name - BCDEdits": {
    "apply": {
      "COMMANDS": {
        "HypervisorOff": {
          "Action": "bcdedit",
          "Name": "hypervisorlaunchtype",
          "Value": "off"
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "HypervisorAuto": {
          "Action": "bcdedit",
          "Name": "hypervisorlaunchtype",
          "Delete": true // bcdedit /deletevalue
        }
      }
    }
  },
  "Option Name - NVIDIA Key": {
    "apply": {
      "COMMANDS": {
        "SetNvidiaValue": {
          "Action": "nvidia_key", // searches for the NVIDIA key in the display adapter key (4d36e968-e325-11ce-bfc1-08002be10318)
          "Values": {
            "RmProfilingAdminOnly": { "Type": "REG_DWORD", "Data": 0 }
          }
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "ClearNvidiaValue": {
          "Action": "nvidia_key",
          "Values": {
            "RmProfilingAdminOnly": { "Action": "deletevalue" }
          }
        }
      }
    }
  },
  "Option Name - Ethernet Key": {
    "apply": {
      "COMMANDS": {
        "SetAdapterPowerSave": {
          "Action": "ethernet_key", // searches for an active adapter (excluding VM adapters) then sets the value directly under that adapter key
          "Values": {
            "AutoPowerSaveModeEnabled": { "Type": "REG_DWORD", "Data": 0 }
          }
        },
        "SetInterfaceDnsWithNetId": {
          "Action": "ethernet_key", // gets NetCfgInstanceId from the ethernet key ({NetID})
          "NetIDPath": "HKLM\\System\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\{NetID}",
          "Values": {
            "NameServer": { "Type": "REG_SZ", "Data": "1.1.1.1" }
          }
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "ResetAdapterPowerSave": {
          "Action": "ethernet_key",
          "Values": {
            "AutoPowerSaveModeEnabled": { "Action": "deletevalue" }
          }
        },
        "ResetInterfaceDnsWithNetId": {
          "Action": "ethernet_key",
          "NetIDPath": "HKLM\\System\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\{NetID}",
          "Values": {
            "NameServer": { "Action": "deletevalue" }
          }
        }
      }
    }
  },
  "Option Name - MMAgent, this was added for the Disable/Enable-MMAgent command": {
    "apply": {
      "COMMANDS": {
        "EnableMemCompr": { 
          "Action": "mmagent", 
          "Name": "MemoryCompression", 
          "Enabled": true, 
          "Elevated": true 
        }
      }
    },
    "revert": {
      "COMMANDS": {
        "DisableMemCompr": { 
          "Action": "mmagent", 
          "Name": "MemoryCompression", 
          "Enabled": false, 
          "Elevated": true 
        }
      }
    }
  }
}
```
