#include <algorithm>
#include <queue>
#include <iostream>


using namespace std;


int main() {
    queue<int> first;
    queue<int> second;
    int x;
    int k = 0;
    for (size_t i = 0; i < 5; i++) {
        cin >> x;
        first.push(x);
    }
    for (size_t i = 0; i < 5; i++) {
        cin >> x;
        second.push(x);
    }
    while (!first.empty() && !second.empty() && k < 1e6) {
        int i = first.front();
        int j = second.front();
        first.pop();
        second.pop();
        if (i == 0 && j == 9) {
            first.push(i);
            first.push(j);
        } else if (i == 9 && j == 0) {
            second.push(i);
            second.push(j);
        } else if (i > j) {
            first.push(i);
            first.push(j);
        } else if (i < j) {
            second.push(i);
            second.push(j);
        }
        k++;
    }
    if (k >= 1e6) {
        cout << "botva\n";
    } else if (first.empty()) {
        cout << "second " << k << "\n";
    } else {
        cout << "first " << k << "\n";
    }
    return 0;
}
