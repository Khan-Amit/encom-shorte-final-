/* sluice.c – Binary Filter for Data Centers */
/* Compile with: gcc sluice.c -o sluice   (Linux) */
/*              tcc sluice.c -o sluice.exe (Turbo C) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Domain definition – each packet/message belongs to a domain */
typedef struct {
    char name[32];          /* e.g., "crypto", "swift", "bank", "ai" */
    int id;                 /* numeric code */
} Domain;

/* A "ripe" candidate – passes the pre‑filter */
typedef struct {
    unsigned char data[256];
    int length;
    Domain domain;
} RipeCandidate;

/* ------------------------------------------------------------------
   The Egg‑Sorter (Binary Pattern Matcher)
   Returns 1 if the candidate is ripe, 0 otherwise.
   Rules are compiled into the code – no interpretation overhead.
   ------------------------------------------------------------------ */
int is_ripe(unsigned char *buffer, int length, Domain d) {
    /* Example pattern: check first 4 bytes == a known header */
    if (length < 4) return 0;

    /* Domain‑specific patterns (add your own here) */
    if (d.id == 1) {  /* crypto domain */
        /* e.g., nonce must be between 0x100000 and 0x20000000 */
        unsigned long nonce = *(unsigned long*)buffer;
        if (nonce < 0x100000 || nonce > 0x20000000) return 0;
        if ((nonce & 0xF) != 0xC) return 0;
    }
    else if (d.id == 2) {  /* SWIFT / financial domain */
        /* e.g., check for valid MT103 header */
        if (buffer[0] != '{' || buffer[1] != '1') return 0;
    }
    /* ... add other domains here */

    return 1;  /* ripe */
}

/* ------------------------------------------------------------------
   The Sluice Gate – forwards only ripe candidates to the next stage
   ------------------------------------------------------------------ */
void sluice_gate(FILE *input, FILE *output, Domain d) {
    unsigned char buffer[256];
    int bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (is_ripe(buffer, bytes, d)) {
            fwrite(buffer, 1, bytes, output);   /* pass through */
        }
        /* else: silently drop the candidate (reject) */
    }
}

/* ------------------------------------------------------------------
   Command‑line interface
   Usage: sluice.exe --domain <id> < input.bin > output.bin
   ------------------------------------------------------------------ */
int main(int argc, char *argv[]) {
    Domain d;
    d.id = 0;
    strcpy(d.name, "default");

    /* crude argument parsing (no library dependencies) */
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--domain") == 0 && i+1 < argc) {
            d.id = atoi(argv[++i]);
            sprintf(d.name, "domain_%d", d.id);
        }
    }

    if (d.id == 0) {
        fprintf(stderr, "Usage: sluice.exe --domain <id> < input > output\n");
        fprintf(stderr, "Domain IDs: 1=crypto, 2=SWIFT, 3=bank, 4=ai ...\n");
        return 1;
    }

    sluice_gate(stdin, stdout, d);
    return 0;
}
