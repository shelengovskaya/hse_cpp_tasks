#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> q;
    string s;
    while (cin >> s) {
        if (s == "ADD") {
            int n;
            cin >> n;
            q.push(n);
        } else if (s == "CLEAR") {
            while (!q.empty()) {
                q.pop();
            }
        } else {
            if (q.empty()) {
                cout << "CANNOT" << "\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}
