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

int getId(const char *val) {
    int row = getPos(val, 7, 127, 'B');
    int col = getPos(val + 7, 3, 7, 'R');

    return row * 8 + col;
}

int main() {
    // getId("BFFFBBFRRR");
    // return 0;


    int mx = 0;

    char buf[16];
    do {
        fgets(buf, 16, stdin);

        if (feof(stdin))
            break;

        int id = getId(buf);

        mx = id > mx ? id : mx;
    } while (1);

    printf("Part 1 : %d\n", mx);

    return 0;
}
