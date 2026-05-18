# Copyright (c) 2026 Seliim Ahmed. All rights reserved.
# This work is protected by copyright law and international treaties.
# Unauthorized reproduction or distribution is prohibited.
#
# Author: Seliim Ahmed
# Email: seliim.ahmed@gmail.com
# License: MIT (see LICENSE file)

class EncomShorte:
    def __init__(self):
        pass

    def is_ripe(self, timestamp, nonce):
        if timestamp % 5 != 0:
            return False
        if nonce < 0x100000 or nonce > 0x20000000:
            return False
        if (nonce & 0xF) != 0xC:
            return False
        return True

    def filter(self, candidates):
        for ts, nc in candidates:
            if self.is_ripe(ts, nc):
                yield (ts, nc)

if __name__ == "__main__":
    es = EncomShorte()
    test_candidates = [
        (1231006505, 0x1dac2b7c),  # ripe
        (1234567890, 0x12345678),   # not ripe
    ]
    for ts, nc in test_candidates:
        print(f"{ts}, {hex(nc)} -> {'ripe' if es.is_ripe(ts, nc) else 'not ripe'}")
