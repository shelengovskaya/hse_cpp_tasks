В ВШЭ проводится письменная контрольная работа. N студентов сдают свои работы в общую стопку, причем некоторые кладут свою работу сверху, а другие (считая, что чем позже их работу проверят, тем лучше) - снизу. Проверяются работы в том порядке, в котором лежат, начиная с верхней. Определите, чья работа будет проверена k-й по счёту.

Формат ввода
Первая строка содержит одно число N, 1 ≤ N ≤ 10000 - число студентов.

Каждая из последующих N строк содержит фамилию студента - строку из латинских букв длиной от 2 до 10 символов, и через пробел слово "top" или "bottom" - положил этот студент свою работу сверху или снизу.

Следующая строка содержит одно число M, 0 ≤ M ≤ 10000 - для какого числа работ нужно определить их автора.

Следующие M строк содержат по одному числу xi от 1 до N - номер в стопке очередной интересующей нас работы.

Формат вывода
Выведите M строк, в i-й строке выведите фамилию студента, чья работа будет проверена xi-й.

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<string> d;
    for (int i = 0; i < n; i++) {
        string s, wh;
        cin >> s >> wh;
        if (wh == "top") {
            d.push_front(s);
        } else {
            d.push_back(s);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cout << d[x - 1] << "\n";
    }
    return 0;
}
