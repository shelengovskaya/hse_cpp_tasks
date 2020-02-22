#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (size_t i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (x > vec.back()) {
            cout << vec.back() << "\n";
            continue;
        }
        auto it = lower_bound(vec.begin(), vec.end(), x);
        if (it == vec.begin()) {
            cout << *it << "\n";
        } else {
            if (n == 1) {
                cout << *it << "\n";
            } else {
                auto left = it;
                --left;
                if (*it - x < x - *left) {
                    cout << *it << "\n";
                } else {
                    cout << *left << "\n";
                }
            }
        }
    }
    return 0;
}
