#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Max entry size
char buf[4096];

int check(char *buf, size_t len) {
    // printf("%zu\n", len);

    buf[len] = 0;
    size_t start = 0;
    size_t nfields = 0;
    for (size_t i = 0; i < len; ++i) {
        if (buf[i] == ':') {
            if (memcmp(buf + start, "byr", 3) == 0 || // 1 ||
                memcmp(buf + start, "iyr", 3) == 0 ||
                memcmp(buf + start, "eyr", 3) == 0 ||
                memcmp(buf + start, "hgt", 3) == 0 ||
                memcmp(buf + start, "hcl", 3) == 0 ||
                memcmp(buf + start, "ecl", 3) == 0 ||
                // memcmp(buf + start, "cid", 3) == 0 ||
                memcmp(buf + start, "pid", 3) == 0)
                    ++nfields;

            for (; i < len && (buf[i] != ' ' && buf[i] != '\n'); ++i);

            start = i + 1;
        }
    }

    // puts("---");
    // printf("%zu ", nfields);

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
