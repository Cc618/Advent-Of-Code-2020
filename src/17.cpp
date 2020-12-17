#include <bits/stdc++.h>

using namespace std;

// For part 1 :
// #define PART1 1

#define DEPTH 6
#define SIZE (8 + DEPTH * 2)

#ifdef PART1
#  define LENGTH (SIZE * SIZE * (1 + 2 * DEPTH))
#else
#  define LENGTH (SIZE * SIZE * (1 + 2 * DEPTH) * (1 + 2 * DEPTH))
#endif

int main() {
    // Think of cubes as tensors
#ifdef PART1
#  define AT(cub, x, y, z, w) (cub)[(x) + SIZE * (y) + SIZE * SIZE * (z)]
#else
#  define AT(cub, x, y, z, w) (cub)[(x) + SIZE * (y) + SIZE * SIZE * (z) + \
        (1 + 2 * DEPTH) * SIZE * SIZE * (w)]
#endif

    // cube[x][y][z]
    array<bool, LENGTH> cube;
    array<bool, LENGTH> cube2;

    for (int i = 0; i < LENGTH; ++i)
        cube[i] = cube2[i] = 0;

    int linei = 0;
    string line;
    while (cin >> line) {
        vector<bool> l(line.size());
        for (int i = 0; i < line.size(); ++i)
            AT(cube, DEPTH + i, DEPTH + linei, DEPTH, DEPTH) = line[i] == '#';

        ++linei;
    }

    // Current cube
    bool use1 = true;
    auto nextPtr = &cube;
    for (int i = 0; i < DEPTH; ++i)
    {
        array<bool, LENGTH>
            &current = use1 ? cube : cube2,
            &next = use1 ? cube2 : cube;

        for (int x = 0; x < SIZE; ++x)
        for (int y = 0; y < SIZE; ++y)
#ifndef PART1
        for (int w = 0; w < 1 + 2 * DEPTH; ++w)
#endif
        for (int z = 0; z < 1 + 2 * DEPTH; ++z) {
            size_t neighbors = 0;

            for (int dx = -1; dx < 2; ++dx)
            for (int dy = -1; dy < 2; ++dy)
#ifndef PART1
            for (int dw = -1; dw < 2; ++dw)
#endif
            for (int dz = -1; dz < 2; ++dz)
                if (
#ifdef PART1
                        !(dx == 0 && dy == 0 && dz == 0) &&
#else
                        !(dx == 0 && dy == 0 && dz == 0 && dw == 0) &&
#endif
                        x + dx >= 0 && x + dx < SIZE &&
                        y + dy >= 0 && y + dy < SIZE &&
#ifndef PART1
                        w + dw >= 0 && w + dw < 2 * DEPTH + 1 &&
#endif
                        z + dz >= 0 && z + dz < 2 * DEPTH + 1)
                    // No errors since part 1 ignores w
                    neighbors += AT(current, x + dx, y + dy, z + dz, w + dw);

            // Active
            if (AT(current, x, y, z, w))
                AT(next, x, y, z, w) = neighbors == 2 || neighbors == 3;
            else
                AT(next, x, y, z, w) = neighbors == 3;
        }

        nextPtr = &next;
        use1 = !use1;
    }

    int sum = 0;
    for (int i = 0; i < LENGTH; ++i)
        sum += (*nextPtr)[i];

#ifdef PART1
    cout << "Part 1 : " << sum << endl;
#else
    cout << "Part 2 : " << sum << endl;
#endif

    return 0;
}
