# Disable Accessibility Features

Disables all kind of accessibility features such as `Voice Access`, `Live Captions`, `Narrator`, `Magnifier`, `OSK` etc. (`SystemSettings > Accessibility`/`Control Panel > All Control Panel Items > Ease of Access Center`). Specific features can be enabled via the suboptions.

## Suboptions

| Suboption | Description |
| --- | --- |
| Audio Description | Hear descriptions of what's happening in videos (when available). |
| Dynamic Scrollbars | "Always show scrollbars", `On` dynamically hide them. |
| [Voice Access](https://support.microsoft.com/en-us/topic/use-voice-access-to-control-your-pc-author-text-with-your-voice-4dcd23ee-f1b9-4fd1-bacc-862ab611f55d) | Modern voice command feature to help you interact with your PC and dictate text. |
| Live Captions | Audio and video will be captioned live on your screen. |
| Notification Box Visbility Time | Time how long the Windows notification boxes should stay opened. |
| Narrator | Narrator reads aloud any text on the screen. You will need speakers. |
| Sound Sentry | Visual notifications for sounds (this option chooses 'None' as visual warning). |
| Color Filters | "Use a color filter to make colors on your screen easier to see and differentiate." |
| Magnifier | Magnifier zooms in anywhere on the screen, and makes everything in that area larger. You can move Magnifier around, lock it in one place, or resize it. |
| On-Screen Keyboard | Tyoe using the mouse or another pointing device such as a joystick by selecting keys from a picture of a keyboard. |
| [Accessibility Insights Telemetry](https://github.com/microsoft/accessibility-insights-windows/blob/main/docs/TelemetryOverview.md#control-of-telemery) | "Accessibility Insights for Windows uses telemetry to better understand what features are most helpful to users, as well as to help identify potential issues that users are experiencing." |

## SystemSettings Captures

Based on `SystemSettings > Accessibility`, not complete yet.

```c
// Visual effects

  // Always show scrollbars
  // Enabled
  HKCU\Control Panel\Accessibility\DynamicScrollbars	Type: REG_DWORD, Length: 4, Data: 0
  // Disabled
  HKCU\Control Panel\Accessibility\DynamicScrollbars	Type: REG_DWORD, Length: 4, Data: 1

  // Transparency effects
  // Enabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize\EnableTransparency	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize\EnableTransparency	Type: REG_DWORD, Length: 4, Data: 0

  // Animation effects (https://noverse.dev/docs/win-config/visibility/minimal-visual-effects/#userpreferencesmask)
  // Enabled
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 92 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 96 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 12 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 16 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 1E 07 80 10 00 00 00
  HKCU\Control Panel\Desktop\WindowMetrics\MinAnimate	Type: REG_SZ, Length: 4, Data: 1
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9E 1E 07 80 12 00 00 00
  // Disabled
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 9C 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 98 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 1E 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 1A 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 07 80 12 00 00 00
  HKCU\Control Panel\Desktop\WindowMetrics\MinAnimate	Type: REG_SZ, Length: 4, Data: 0
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 07 80 10 00 00 00

  // Dismiss notifications after this amount of time
  // 5 seconds
  HKCU\Control Panel\Accessibility\MessageDuration	Type: REG_DWORD, Length: 4, Data: 5
  // 5 minutes
  HKCU\Control Panel\Accessibility\MessageDuration	Type: REG_DWORD, Length: 4, Data: 300

// Mouse pointer and touch

  // Size
  // 1 (min)
  HKCU\Software\Microsoft\Accessibility\CursorSize	Type: REG_DWORD, Length: 4, Data: 1
  // 15 (max)
  HKCU\Software\Microsoft\Accessibility\CursorSize	Type: REG_DWORD, Length: 4, Data: 15

  // Touch indicator
  // Enabled
  HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 1
  HKCU\Control Panel\Cursors\GestureVisualization	Type: REG_DWORD, Length: 4, Data: 31
    // Make the circle darker and larger
    HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 2
  // Disabled
  HKCU\Control Panel\Cursors\ContactVisualization	Type: REG_DWORD, Length: 4, Data: 0
  HKCU\Control Panel\Cursors\GestureVisualization	Type: REG_DWORD, Length: 4, Data: 2

// Text cursor

  // Text cursor indicator
  // Enabled
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 32, Data: cursorindicator
  // Disabled
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 2, Data: 

  // Text cursor thickness
  // 1 (min)
  HKCU\Control Panel\Desktop\CaretWidth	Type: REG_DWORD, Length: 4, Data: 1
  // 20 (max)
  HKCU\Control Panel\Desktop\CaretWidth	Type: REG_DWORD, Length: 4, Data: 20

// Magnifier

  // Zoom level
  // 100%
  HKCU\Software\Microsoft\ScreenMagnifier\Magnification	Type: REG_DWORD, Length: 4, Data: 100
  // 500%
  HKCU\Software\Microsoft\ScreenMagnifier\Magnification	Type: REG_DWORD, Length: 4, Data: 500

  // Zoom increment
  // 5%
  HKCU\Software\Microsoft\ScreenMagnifier\ZoomIncrement	Type: REG_DWORD, Length: 4, Data: 5
  // 400%
  HKCU\Software\Microsoft\ScreenMagnifier\ZoomIncrement	Type: REG_DWORD, Length: 4, Data: 400

  // View
  // Docked
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 1
    // Have Magnifier follow my (Docked & Full screen only), these are just bools
    // Mouse pointer
    HKCU\Software\Microsoft\ScreenMagnifier\FollowMouse	Type: REG_DWORD, Length: 4, Data: 0
    // Keyboard focus
    HKCU\Software\Microsoft\ScreenMagnifier\FollowFocus	Type: REG_DWORD, Length: 4, Data: 0
    // Text cursor
    HKCU\Software\Microsoft\ScreenMagnifier\FollowCaret	Type: REG_DWORD, Length: 4, Data: 0
    // Narrator cursor
    HKCU\Software\Microsoft\ScreenMagnifier\FollowNarrator	Type: REG_DWORD, Length: 4, Data: 0
  
  // Full screen
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 2
    // Keep the mouse pointer
    // Within the edges of the screen
    HKCU\Software\Microsoft\ScreenMagnifier\FullScreenTrackingMode	Type: REG_DWORD, Length: 4, Data: 0
    // Centered on the screen
    HKCU\Software\Microsoft\ScreenMagnifier\FullScreenTrackingMode	Type: REG_DWORD, Length: 4, Data: 1

    // Keep the text cursor
    // Within the edges of the screen
    HKCU\Software\Microsoft\ScreenMagnifier\CenterTextInsertionPoint	Type: REG_DWORD, Length: 4, Data: 0
    // Centered on the screen
    HKCU\Software\Microsoft\ScreenMagnifier\CenterTextInsertionPoint	Type: REG_DWORD, Length: 4, Data: 1

  // Lens
  HKCU\Software\Microsoft\ScreenMagnifier\MagnificationMode	Type: REG_DWORD, Length: 4, Data: 3
    // Change lens size
    // Height (in 10 steps)
    // 10 (min)
    HKCU\Software\Microsoft\ScreenMagnifier\LensHeight	Type: REG_DWORD, Length: 4, Data: 10
    // 100 (max)
    HKCU\Software\Microsoft\ScreenMagnifier\LensHeight	Type: REG_DWORD, Length: 4, Data: 100

    // Width (in 10 steps)
    // 10 (min)
    HKCU\Software\Microsoft\ScreenMagnifier\LensWidth	Type: REG_DWORD, Length: 4, Data: 10
    // 100 (max)
    HKCU\Software\Microsoft\ScreenMagnifier\LensWidth	Type: REG_DWORD, Length: 4, Data: 100

  // Invert colors
  // Enabled
  HKCU\Software\Microsoft\ScreenMagnifier\Invert	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ScreenMagnifier\Invert	Type: REG_DWORD, Length: 4, Data: 0
  
  // Smooth edges of images and text
  // Enabled
  HKCU\Software\Microsoft\ScreenMagnifier\UseBitmapSmoothing	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ScreenMagnifier\UseBitmapSmoothing	Type: REG_DWORD, Length: 4, Data: 0

  // Reading shortcut
  // Ctrl + Alt
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 1
  // Caps Lock
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 2
  // Insert
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 4
  // Caps Lock or Insert
  HKCU\Software\Microsoft\ScreenMagnifier\ModifierKey	Type: REG_DWORD, Length: 4, Data: 6

// Color filters

  // Color filters
  // Enabled
  HKCU\Software\Microsoft\ColorFiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 30, Data: colorfiltering
    // Red-green
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 3

    // Red-green
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Blue-yellow
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Grayscale
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 4

    // Grayscale inverted
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 2

    // Inverted
    HKCU\Software\Microsoft\ColorFiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1
    HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\Configuration	Type: REG_SZ, Length: 58, Data: magnifierpane,colorfiltering
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\Active	Type: REG_DWORD, Length: 4, Data: 1
    HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Accessibility\Session1\ATConfig\colorfiltering\FilterType	Type: REG_DWORD, Length: 4, Data: 1

  // Disabled
  HKCU\Software\Microsoft\ColorFiltering\Active	Type: REG_DWORD, Length: 4, Data: 0
  HKCU\Software\Microsoft\Windows NT\CurrentVersion\Accessibility\Configuration	Type: REG_SZ, Length: 2, Data: 

  // Keyboard shortcut for color filters
  // Enabled
  HKCU\Software\Microsoft\ColorFiltering\HotkeyEnabled	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\ColorFiltering\HotkeyEnabled	Type: REG_DWORD, Length: 4, Data: 0

// Audio

  // Mono audio
  // Enabled
  HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Software\Microsoft\Multimedia\Audio\AccessibilityMonoMixState	Type: REG_DWORD, Length: 4, Data: 0

  // Flash my screen during audio notifications
  // Never
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 0
  // Flash the title bar of the active window
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 1
  // Flash the active window
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 2
  // Flash the entire screen
  HKCU\Control Panel\Accessibility\SoundSentry\WindowsEffect	Type: REG_SZ, Length: 4, Data: 3

// Keyboard

  // Sticky keys, this is a bitmask
  // Enabled
  HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 1
    // Keyboard shortcut for Sticky keys (bit 2)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 4
    // Show the Sticky keys icon on the taskbar (bit 5)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 32
    // Lock shortcut keys when pressed twice in a row (bit 7)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 8, Data: 128
    // Turn of Sticky keys when two keys are pressed at the same time (bit 8)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 8, Data: 256
    // Play a sound when shortcut keys are pressed and released (bit 6)
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 64
  // Disabled
  HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Filter keys, also a bitmask
  // Enabled
  HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 1
    // Keboard shortcut for Filter keys (bit 2)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 4
    // Show the Filter keys icon on the taskbar (bit 5)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 32
    // Beep when keys are pressed or accepted (bit 6)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 64
    // Ignore quick keystrokes (slow keys)
      // 0.0 seconds (off)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 0
      // 0.3 seconds (min)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 300
      HKCU\Software\Microsoft\Osk\LastKeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 300
      // 20.0 seconds (max)
      HKCU\Software\Microsoft\Osk\KeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 20000
      HKCU\Software\Microsoft\Osk\LastKeystrokeDelay	Type: REG_DWORD, Length: 4, Data: 20000
    // Ignore unintended keystrokes (bounce keys)
      // 0.0 seconds (off)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 0
      // 0.3 seconds (min)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 300
      HKCU\Software\Microsoft\Osk\LastBounceTime	Type: REG_DWORD, Length: 4, Data: 300
      // 2.0 seconds (max)
      HKCU\Software\Microsoft\Osk\BounceTime	Type: REG_DWORD, Length: 4, Data: 2000
      HKCU\Software\Microsoft\Osk\LastBounceTime	Type: REG_DWORD, Length: 4, Data: 2000
    // Ignore repeated keystrokes (repeated keys)
      // Wait before accepting the first repeatable keystroke
        // 0.0 seconds (off)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        // 0.3 seconds (min)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        // 2.0 seconds (max)
        HKCU\Software\Microsoft\Osk\FirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
        HKCU\Software\Microsoft\Osk\LastFirstRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
      // Wait before accepting subsequent repeated keystrokes
        // 0.0 seconds (off)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 0
        // 0.3 seconds (min)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 300
        // 2.0 seconds (max)
        HKCU\Software\Microsoft\Osk\NextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
        HKCU\Software\Microsoft\Osk\LastNextRepeatDelay	Type: REG_DWORD, Length: 4, Data: 2000
  // Disabled
  HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Toggle keys
  // Enabled
  HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 1
  // Disabled
  HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0

  // Notification preferences
    // Nofify me when I turn on Sticky, Filter, or Toggle keys from the keyboard
    // Enabled (bit 3)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 8
    HKCU\Control Panel\Accessibility\Warning Sounds	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\Warning Sounds	Type: REG_DWORD, Length: 4, Data: 0

    // Play a sound when I turn Sticky, Filter, or Toggle keys on or off from the keyboard
    // Enabled (bit 4)
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 6, Data: 16
    HKCU\Control Panel\Accessibility\Sound on Activation	Type: REG_DWORD, Length: 4, Data: 1
    // Disabled
    HKCU\Control Panel\Accessibility\Keyboard Response\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\StickyKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\ToggleKeys\Flags	Type: REG_SZ, Length: 4, Data: 0
    HKCU\Control Panel\Accessibility\Sound on Activation	Type: REG_DWORD, Length: 4, Data: 0

  // Underline access keys
  // Enabled
  HKCU\Control Panel\Accessibility\Keyboard Preference\On	Type: REG_SZ, Length: 4, Data: 1
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: B0 12 03 80 10 00 00 00
  // Disabled
  HKCU\Control Panel\Accessibility\Keyboard Preference\On	Type: REG_SZ, Length: 4, Data: 0
  HKCU\Control Panel\Desktop\UserPreferencesMask	Type: REG_BINARY, Length: 8, Data: 90 12 03 80 10 00 00 00

  // Use the Print screen key to open screen capture
  // Enabled
  HKCU\Control Panel\Keyboard\PrintScreenKeyForSnippingEnabled	Type: REG_DWORD, Length: 4, Data: 1
  // Disabled
  HKCU\Control Panel\Keyboard\PrintScreenKeyForSnippingEnabled	Type: REG_DWORD, Length: 4, Data: 0

// Mouse

  // Mouse keys (bitmask again)
  // Enabled
  HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159
    // Only use mouse keys when Num lock is on (bit 7)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 6, Data: 31
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Show the mouse keys icon on the taskbar (bit 5)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 191
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Hold the Ctrl key to speed up and the Shift key to slow down (bit 6)
    // Enabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 223
    // Disabled
    HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 159

    // Mouse keys speed
    // 1 (min)
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 6, Data: 10
    // 50
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 182
    // 75
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 266
    // 100 (max)
    HKCU\Control Panel\Accessibility\MouseKeys\MaximumSpeed	Type: REG_SZ, Length: 8, Data: 358

    // Mouse keys acceleration
    // 1 (min)
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 5000
    // 50
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 3040
    // 75
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 2000
    // 100 (max)
    HKCU\Control Panel\Accessibility\MouseKeys\TimeToMaximumSpeed	Type: REG_SZ, Length: 10, Data: 1000
  // Disabled
  HKCU\Control Panel\Accessibility\MouseKeys\Flags	Type: REG_SZ, Length: 8, Data: 158
```

