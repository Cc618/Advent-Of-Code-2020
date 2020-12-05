#include <stdio.h>
#include <stddef.h>

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

int main() {
    int result1 = part1(stdin);

    printf("Part 1 : %d\n", result1);

    return 0;
}
