# Agent Reference

## Flashing to ESP32-C3 via PlatformIO

`pio` and `platformio` are not on PATH. Use the full path to the executable inside the PlatformIO virtual environment:

```
C:\Users\pspyc\.platformio\penv\Scripts\platformio.exe
```

### Flash a specific example

```powershell
& "C:\Users\pspyc\.platformio\penv\Scripts\platformio.exe" run --target upload --project-dir "<absolute-path-to-example-folder>"
```

Example — flash `examples/ActiveBoxes`:

```powershell
& "C:\Users\pspyc\.platformio\penv\Scripts\platformio.exe" run --target upload --project-dir "c:\Users\pspyc\OneDrive\Dokumenty\PlatformIO\Projects\ApexMSP\examples\ActiveBoxes"
```

### Build only (no upload)

```powershell
& "C:\Users\pspyc\.platformio\penv\Scripts\platformio.exe" run --project-dir "<path>"
```

### Notes

- Board auto-detected on **COM4** (ESP32-C3-DevKitM-1).
- Each example has its own `platformio.ini` with `src_dir = .` and `lib_extra_dirs = ../..` pointing back to the library root.
- Use the `PowerShell` tool, not `Bash`, for all PlatformIO commands on this machine.
