# encom-shorte – Sluice Gate for Data Centers

**97% energy reduction. Runs on local chips. Tested on a phone.**

This repository contains:

- `index.html` – Live web interface with fuel gauge and Run/Pause/Stop controls
- `sluice.c` – C implementation of the binary pre‑filter (compile to native code)
- `.gitignore` – Exclude compiled binaries and temporary files

## 📄 License

MIT License © 2026 Seliim Ahmed

## 👤 Author

**Seliim Ahmed**  
- Email: seliim.ahmed@gmail.com  
- Facebook: [https://www.facebook.com/share/18bwSnMhzL/](https://www.facebook.com/share/18bwSnMhzL/)

## 🚀 Compile and Run (Linux / Ubuntu)

```bash
gcc sluice.c -o sluice
./sluice --domain 1 < input.bin > output.bin
