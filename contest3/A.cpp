#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> m;
    string s;
    int maxx = 0;
    while (cin >> s) {
        for (const auto& it : s) {
            m[it]++;
            if (m[it] > maxx) {
                maxx = m[it];
            }
        }
    }
    while (maxx > 0) {
        for (const auto& [key, value] : m) {
            if (value == maxx) {
                cout << "#";
                m[key]--;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
        maxx--;
    }
    for (const auto& [key, value] : m) {
        cout << key;
    }
    cout << "\n";
}
