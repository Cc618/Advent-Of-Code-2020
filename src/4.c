#include <stdio.h>
#include <string.h>
#include <stddef.h>

// #define PART1

// Max entry size
char buf[4096];

// Token valid
int isvalid(char *name, char *val) {
    return  strcmp(name, "byr") == 0 ||
            strcmp(name, "iyr") == 0 ||
            strcmp(name, "eyr") == 0 ||
            strcmp(name, "hgt") == 0 ||
            strcmp(name, "hcl") == 0 ||
            strcmp(name, "ecl") == 0 ||
            strcmp(name, "pid") == 0;
}

int check(char *buf, size_t len) {
    buf[len] = 0;

    const char *sep = " \n";
    char *tok = strtok(buf, sep);

    size_t nfields = 0;
    while (tok) {
        char *colon = strchr(tok, ':');
        *colon = 0;
        nfields += isvalid(tok, colon + 1);

        tok = strtok(NULL, sep);
    }

    return nfields == 7;
}

int main() {
    int c;
    size_t bufi = 0;
    size_t valid = 0;
    do {
        c = fgetc(stdin);
        if (feof(stdin)) {
            valid += check(buf, bufi - 1);

            break;
        }

        if (bufi > 0 && buf[bufi - 1] == '\n' && c == '\n') {
            valid += check(buf, bufi - 1);

            bufi = 0;
        } else
            buf[bufi++] = c;
    } while (1);

    printf("Part 1: %zu\n", valid);

    return 0;
}
