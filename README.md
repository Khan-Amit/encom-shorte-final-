# encom-shorte-final-
# encom-shorte – Sluice Gate for Data Centers
concept creation ©to Seliim Ahmed 
email: seliim.ahmed@gmail.com 
https://www.facebook.com/share/18bwSnMhzL/
Facebook 
**97% energy reduction. Runs on local chips. Tested on a phone.**

This repository contains:

- `sluice.c` – C implementation of the binary pre‑filter (compile to native code)
- `dashboard.html` – Live web interface with fuel gauge and Run/Pause/Stop controls
- `.gitignore` – Exclude compiled binaries and temporary files

## Compile and Run (Linux / Ubuntu)

```bash
gcc sluice.c -o sluice
./sluice --domain 1 < input.bin > output.bin
