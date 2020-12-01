// Complexity : O(N log N)

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Number of entries in the input file
    constexpr int N = 200;

    vector<int> inputs(N);
    for (int i = 0; i < N; ++i)
        cin >> inputs[i];

    sort(inputs.begin(), inputs.end());

    for (int i = 0; i < N; ++i)
        if (binary_search(inputs.begin(), inputs.end(), 2020 - inputs[i])) {
            cout << (2020 - inputs[i]) * inputs[i] << endl;
            break;
        }

    return 0;
}
