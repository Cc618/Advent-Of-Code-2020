// 1 Complexity : O(N log N)
// 2 Complexity : O(N^2 log N)

#include <bits/stdc++.h>

using namespace std;

#define PART2

int main() {
    // Number of entries in the input file
    constexpr int N = 200;

    vector<int> inputs(N);
    for (int i = 0; i < N; ++i)
        cin >> inputs[i];

    sort(inputs.begin(), inputs.end());

#ifdef PART1
    for (int i = 0; i < N; ++i)
        if (binary_search(inputs.begin(), inputs.end(), 2020 - inputs[i])) {
            cout << (2020 - inputs[i]) * inputs[i] << endl;
            return 0;
        }
#else
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (binary_search(inputs.begin(), inputs.end(), 2020 - inputs[i]
                        - inputs[j])) {
                cout << (2020 - inputs[i] - inputs[j]) * inputs[i] * inputs[j]
                    << endl;
                return 0;
            }
#endif

    return -1;
}
