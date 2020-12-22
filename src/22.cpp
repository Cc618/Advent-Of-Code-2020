#include <bits/stdc++.h>

using namespace std;

// Uncomment for part 1
#define PART2 1

#define ul unsigned long long

static void print(const list<int> &l) {
    for (auto i : l)
        cout << i << " ";
    cout << endl;
}

ul hashround(const list<int>& p1, const list<int>& p2) {
    ul seed = p1.size();
    for (auto i : p1) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    seed += p2.size() * 100;
    for (auto i : p2) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }

    return seed;
}

// (winnerdeck, p1wins)
pair<list<int>, bool> game(list<int> p1, list<int> p2) {
    unordered_set<ul> rounds;
    while (p1.size() != 0 && p2.size() != 0) {
#ifdef PART2
        ul h = hashround(p1, p2);
        // There is already a round like this
        if (rounds.find(h) != rounds.end()) {
            return { p1, true };
        } else
            rounds.insert(h);
#endif

        int c1 = p1.front();
        int c2 = p2.front();
        p1.pop_front();
        p2.pop_front();

        bool p1wins;

#ifdef PART2
        // We can launch a recursive game
        if (p1.size() >= c1 && p2.size() >= c2) {
            auto p1deck = list<int>();
            auto p2deck = list<int>();
            auto c1it = p1.begin();
            auto c2it = p2.begin();
            for (int i = 0; i < c1; ++i) {
                p1deck.push_back(*c1it);
                ++c1it;
            }
            for (int i = 0; i < c2; ++i) {
                p2deck.push_back(*c2it);
                ++c2it;
            }

            auto [winner, _p1wins] = game(p1deck, p2deck);
            p1wins = _p1wins;
        } else
#endif
        p1wins = c1 > c2;

        if (p1wins) {
            p1.push_back(c1);
            p1.push_back(c2);
        } else {
            p2.push_back(c2);
            p2.push_back(c1);
        }
    }

    return { !p1.size() ? p2 : p1, p1.size() != 0 };
}

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

    auto [winner, p1wins] = game(p1, p2);

    ul mul = winner.size();
    ul total = 0;
    for (auto i : winner) {
        total += mul-- * i;
    }

#ifdef PART2
    cout << "Part 2 : "
#else
    cout << "Part 1 : "
#endif
        << total << endl;

    return 0;
}
