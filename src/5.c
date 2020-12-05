// Compile with :
// nasm -o asm.o -f elf64 5.asm && gcc -static -o program 5.c asm.o

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

extern int getPos(const char *val, int len, int high, char upper);

// int getPos(const char *val, int len, int high, char upper) {
//     int low = 0;
//     for (int i = 0; i < len; ++i) {
//         int mid = (high + low) / 2;
//         if (val[i] == upper)
//             low = mid + 1;
//         else
//             high = mid;
//     }

//     return low;
// }

extern int getId(const char *val);

// int getId(const char *val) {
//     int row = getPos(val, 7, 127, 'B');
//     int col = getPos(val + 7, 3, 7, 'R');

//     return row * 8 + col;
// }

extern int part1(FILE *fin);

// int cpart1(FILE *fin) {
//     int mx = 0;

//     char buf[16];
//     do {
//         fgets(buf, 16, fin);

//         if (feof(fin))
//             break;

//         int id = getId(buf);

//         mx = id > mx ? id : mx;
//     } while (1);

//     return mx;
// }

int intcmp(const void *a, const void *b) {
    return *(const int*)a > *(const int*)b;
}

#define NIDS 761
int part2(FILE *fin) {
    char buf[16];
    int *ids = malloc(4 * NIDS);
    int idsptr = 0;
    do {
        fgets(buf, 16, fin);

        if (feof(fin))
            break;

        int id = getId(buf);
        ids[idsptr++] = id;
    } while (1);

    // Sort ids
    qsort(ids, NIDS, 4, intcmp);

    for (int i = 0; i < NIDS - 1; ++i)
        if (ids[i + 1] - ids[i] != 1)
            return ids[i] + 1;

    free(ids);

    // Error
    return -1;
}

int main() {
    // int result1 = part1(stdin);
    int result2 = part2(stdin);

    // printf("Part 1 : %d\n", result1);
    printf("Part 2 : %d\n", result2);

    return 0;
}
