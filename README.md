# encom-shorte – Sluice Gate for Data Centers

**97% energy reduction. Runs on local chips. Tested on a phone.**

This repository contains:

- `sluice.c` – C implementation of the binary pre‑filter (compile to native code)
- `prefilter.py` – Python version of the egg‑sorter (runs on any device)
- `index.html` – Live web interface with fuel gauge and Run/Pause/Stop controls
- `.gitignore` – Exclude compiled binaries and temporary files

## 📄 License

MIT License © 2026 Seliim Ahmed

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## 👤 Author

**Seliim Ahmed**
- Email: seliim.ahmed@gmail.com
- Facebook: https://www.facebook.com/share/18bwSnMhzL/

## 🚀 Compile and Run (Linux / Ubuntu)

```bash
gcc sluice.c -o sluice
./sluice --domain 1 < input.bin > output.bin
