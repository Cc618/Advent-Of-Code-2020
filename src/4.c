#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

// Uncomment for part 1
// #define PART1

// Max entry size
char buf[4096];

static int byrValid(char *val) {
    if (strlen(val) != 4)
        return 0;

    long v = atol(val);

    return v >= 1920 && v <= 2002;
}

static int iyrValid(char *val) {
    if (strlen(val) != 4)
        return 0;

    long v = atol(val);

    return v >= 2010 && v <= 2020;
}

static int eyrValid(char *val) {
    if (strlen(val) != 4)
        return 0;

    long v = atol(val);

    return v >= 2020 && v <= 2030;
}

static int hgtValid(char *val) {
    if (strlen(val) == 5) {
        // cm
        if (strcmp(val + 3, "cm")) return 0;

        val[3] = 0;
        long v = atol(val);

        return 150 <= v && v <= 193;
    } else if (strlen(val) == 4) {
        // in
        if (strcmp(val + 2, "in")) return 0;

        val[2] = 0;
        long v = atol(val);

        return 59 <= v && v <= 76;
    }

    return 0;
}

static int hclValid(char *val) {
    if (strlen(val) != 7) return 0;
    if (*val != '#') return 0;

    char s[7];
    sscanf(val + 1, "%[0-9a-f]", s);

    return strlen(s) == 6;
}

static int eclValid(char *val) {
    static const char *vals[] = {
        "amb",
        "blu",
        "brn",
        "gry",
        "grn",
        "hzl",
        "oth",
    };

    for (int i = 0; i < 7; ++i)
        if (!strcmp(val, vals[i])) return 1;

    return 0;
}

static int pidValid(char *val) {
    if (strlen(val) != 9) return 0;

    while (*val)
        if (!isdigit(*val++)) return 0;

    return 1;
}

// Token valid
int isvalid(char *name, char *val) {
#ifdef PART1
    return  strcmp(name, "byr") == 0 ||
            strcmp(name, "iyr") == 0 ||
            strcmp(name, "eyr") == 0 ||
            strcmp(name, "hgt") == 0 ||
            strcmp(name, "hcl") == 0 ||
            strcmp(name, "ecl") == 0 ||
            strcmp(name, "pid") == 0;
#else
    struct {
        const char *name;
        int (*validator)(char *val);
    } entries[] = {
        { "byr", byrValid },
        { "iyr", iyrValid },
        { "eyr", eyrValid },
        { "hgt", hgtValid },
        { "hcl", hclValid },
        { "ecl", eclValid },
        { "pid", pidValid },
    };

    for (int i = 0; i < 7; ++i)
        if (strcmp(entries[i].name, name) == 0)
            return entries[i].validator(val);

    return 0;
#endif
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
    // // Examples (contains memory leaks)
    // printf("%d\n", isvalid("byr", strdup("2002")));
    // printf("%d\n", isvalid("byr", strdup("2003")));
    // puts("");

    // printf("%d\n", isvalid("hgt", strdup("60in")));
    // printf("%d\n", isvalid("hgt", strdup("190cm")));
    // printf("%d\n", isvalid("hgt", strdup("190in")));
    // printf("%d\n", isvalid("hgt", strdup("190")));
    // puts("");

    // printf("%d\n", isvalid("hcl", strdup("#123abc")));
    // printf("%d\n", isvalid("hcl", strdup("#123abz")));
    // printf("%d\n", isvalid("hcl", strdup("123abc")));
    // puts("");

    // printf("%d\n", isvalid("ecl", strdup("brn")));
    // printf("%d\n", isvalid("ecl", strdup("wat")));
    // puts("");

    // printf("%d\n", isvalid("pid", strdup("000000001")));
    // printf("%d\n", isvalid("pid", strdup("0123456789")));
    // puts("");

    // return 0;

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

#ifdef PART1
    printf("Part 1: %zu\n", valid);
#else
    printf("Part 2: %zu\n", valid);
#endif

    return 0;
}
