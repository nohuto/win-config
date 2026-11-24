# Disable F1 Help Key

Blocks `HelpPane.exe` (Help and Support Windows desktop application) from starting, which was the help component in `W8`/`W8.1`. The executeable still exists but calls to it will either start the `Get Started` application (if user is offline), or opens a browser instance and redirects the browser to an online topic. Note that `HelpPane` still handles the `F1` shortcut.

If the option is disabled, pressing `F1` on your desktop will take you to a search query like:

```powershell
https://www.bing.com/search?q=how+to+get+help+in+windows+11
```
