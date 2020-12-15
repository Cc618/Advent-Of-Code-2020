#include <bits/stdc++.h>

using namespace std;

int main() {
    // Returns the index of the last occurence of the number
    unordered_map<int, int> lastPos;

    string s;
    cin >> s;
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    vector<int> nb;

    int current;
    int i = 0;
    while (ss >> current) {
        nb.push_back(current);
        lastPos[current] = i;
        ++i;
    }

    // We suppose no duplicates, the last one is not yet for searching
    lastPos.erase(nb.back());

    int next;
    for (int i = nb.size(); i < 2020; ++i) {
        auto search = lastPos.find(current);
        if (search == lastPos.end()) {
            // New val
            next = 0;
        } else {
            next = i - (*search).second - 1;
        }

        // Update after the map
        lastPos[current] = i - 1;
        current = next;
    }

    cout << "Part 1 : " << current << endl;

    return 0;
}
