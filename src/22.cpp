#include <bits/stdc++.h>

using namespace std;

#define ul unsigned long long

int main() {
    list<int> p1;
    list<int> p2;

    string line;
    getline(cin, line);
    while (getline(cin, line) && line != "")
        p1.push_back(stoi(line));

    getline(cin, line);
    while (getline(cin, line))
        p2.push_back(stoi(line));

    while (p1.size() != 0 && p2.size() != 0) {
        int c1 = p1.front();
        int c2 = p2.front();
        p1.pop_front();
        p2.pop_front();

        if (c1 > c2) {
            p1.push_back(c1);
            p1.push_back(c2);
        } else {
            p2.push_back(c2);
            p2.push_back(c1);
        }
    }

    list<int>& winner = !p1.size() ? p2 : p1;
    ul mul = winner.size();
    cout << mul << endl;
    ul total = 0;
    for (auto i : winner) {
        total += mul-- * i;
    }

    cout << "Part 1 : " << total << endl;

    return 0;
}
