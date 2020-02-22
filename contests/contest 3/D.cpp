Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.

Формат ввода
На вход поступают слова (по одному в строке), состоящие из маленьких латинских букв алфавита. Длина слов не превосходит 100 символов, а количество слов не превосходит 1000.

Формат вывода
Выведите в алфавитном порядке без пробелов список букв, присутствующих в каждом слове.

#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    string s;
    set<char> st;
    map<char, int> m;
    int n = 0;
    while(cin >> s) {
        for (size_t i = 0; i < s.size(); i++) {
            st.insert(s[i]);
        }
        for (const auto& it : st) {
            m[it]++;
        }
        st.clear();
        n++;
    }
    for (const auto& [key, value] : m) {
        if (value == n) {
            cout << key;
        }
    }
    return 0;
}
