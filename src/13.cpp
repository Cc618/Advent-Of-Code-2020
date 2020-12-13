#include <bits/stdc++.h>

using namespace std;

int main() {
    int early;
    cin >> early;

    string dataStr;
    cin >> dataStr;

    replace(dataStr.begin(), dataStr.end(), ',', ' ');
    replace(dataStr.begin(), dataStr.end(), 'x', ' ');

    vector<int> buses;
    stringstream ss(dataStr);
    int tmp;
    while (ss >> tmp) {
        buses.push_back(tmp);
        cout << tmp << endl;
    }

    int minId;
    int minWait = 0xffff;
    for (auto id : buses) {
        int wait = id - early % id;

        if (wait < minWait) {
            minId = id;
            minWait = wait;
        }
    }

    cout << "Part 1 : " << minId * minWait << endl;

    return 0;
}
