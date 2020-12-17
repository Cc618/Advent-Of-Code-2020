#include <bits/stdc++.h>

using namespace std;

#define DEPTH 6
#define SIZE (8 + DEPTH * 2)

int main() {
#define AT(cub, x, y, z) (cub)[(x) + SIZE * (y) + SIZE * SIZE * (z)]
    // cube[x][y][z]
    array<bool, SIZE * SIZE * (1 + 2 * DEPTH)> cube;
    array<bool, SIZE * SIZE * (1 + 2 * DEPTH)> cube2;

    for (int i = 0; i < SIZE * SIZE * (1 + 2 * DEPTH); ++i)
        cube[i] = cube2[i] = 0;

    int linei = 0;
    string line;
    while (cin >> line) {
        vector<bool> l(line.size());
        for (int i = 0; i < line.size(); ++i)
            AT(cube, DEPTH + i, DEPTH + linei, DEPTH) = line[i] == '#';

        ++linei;
    }

    // Current cube
    bool use1 = true;
    auto nextPtr = &cube;
    for (int i = 0; i < DEPTH; ++i)
    {
        array<bool, SIZE * SIZE * (1 + 2 * DEPTH)>
            &current = use1 ? cube : cube2,
            &next = use1 ? cube2 : cube;

        for (int x = 0; x < SIZE; ++x)
        for (int y = 0; y < SIZE; ++y)
        for (int z = 0; z < 1 + 2 * DEPTH; ++z) {
            size_t neighbors = 0;

            for (int dx = -1; dx < 2; ++dx)
            for (int dy = -1; dy < 2; ++dy)
            for (int dz = -1; dz < 2; ++dz)
                if (!(dx == 0 && dy == 0 && dz == 0) &&
                        x + dx >= 0 && x + dx < SIZE &&
                        y + dy >= 0 && y + dy < SIZE &&
                        z + dz >= 0 && z + dz < 2 * DEPTH + 1)
                    neighbors += AT(current, x + dx, y + dy, z + dz);

            // Active
            if (AT(current, x, y, z))
                AT(next, x, y, z) = neighbors == 2 || neighbors == 3;
            else
                AT(next, x, y, z) = neighbors == 3;
        }

        // Disp main slice
        // int z = DEPTH;
        // for (int y = 0; y < SIZE; ++y) {
        //     for (int x = 0; x < SIZE; ++x)
        //         cout << (AT(next, x, y, z) ? "#" : ".");

        //     cout << endl;
        // }
        // cout << endl;

        nextPtr = &next;
        use1 = !use1;
    }

    int sum = 0;
    for (int i = 0; i < SIZE * SIZE * (1 + 2 * DEPTH); ++i)
        sum += (*nextPtr)[i];

    cout << "Part 1 : " << sum << endl;

    return 0;
}
