#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;


int main() {
    string s;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                           13, 14, 15, 16, 17, 18, 19, 20};
    vector<char> symbols = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                            'H', 'I', 'J', 'K', 'L', 'M', 'N',
                            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                            'V', 'W', 'X', 'Y', 'Z'};
    while (getline(cin, s)) {
        int i = 0;
        vector<int> num;
        vector<char> ch;
        string ss = "";
        while (i < s.size() && s[i] != ' ') {
            ss += s[i];
            i++;
        }
        i++;
        cout << ss;
        ss = "";
        int n, kol = 0;
        while (i < s.size() && s[i] != ' ') {
            kol = kol*10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < s.size()) {
            string ss = "";
            n = 0;
            while (i < s.size() && s[i] != ' ') {
                ss += s[i];
                if (s[i] - 'A' < 27 && s[i] - 'A' >= 0) {
                    ch.push_back(s[i]);
                } else {
                    n = n*10 + s[i] - '0';
                }
            if (n != 0) {
                num.push_back(n);
            }
            i++;
            }
            i++;
        }
        if (!num.empty() || (num.empty() && ch.empty())) {
            vector<int> ans_num;
            auto it = set_difference(numbers.begin(), numbers.begin() + kol,
                    num.begin(), num.end(), inserter(ans_num, ans_num.begin()));
            for (const auto& it : ans_num) {
                cout << " " << it;
            }
        } else if (!ch.empty()) {
            vector<char> ans_sym;
            auto it = set_difference(symbols.begin(), symbols.begin() + kol,
                                     ch.begin(), ch.end(), inserter(ans_sym, ans_sym.begin()));
            for (const auto& it : ans_sym) {
                cout << " " << it;
            }
        }
        cout << '\n';
    }
    return 0;
}
