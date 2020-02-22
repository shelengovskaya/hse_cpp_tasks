Напишите программу, которая будет по списку поступающих и университетов определять, кто именно поступит в каждый университет.

В каждом университете есть лимит мест, у каждого абитуриента есть определенный набранный балл и список предпочтений.

Распределение происходит следующим образом: абитуриенты сортируются по убыванию баллов, при равенстве - по возрастанию даты рождения и, затем, по фамилии и имени.

Далее каждый абитуриент по очереди зачисляется в первый университет из его списка, в котором еще остались места (если таких нет - не зачисляется никуда).

Формат ввода
Первая строка содержит одно целое число N от 1 до 104 - количество университетов.

Следующие N строк содержат строку их латинских символов длиной от 5 до 15 символов и число от 0 до 109 - название и максимальное количество студентов для очередного университета.

Следующая строка содержит целое число M от 0 до 104 - количество абитуриентов.

Далее идут M строк, каждая из которых содержит две строки длиной от 5 до 15 символов - имя и фамилию очередного абитурента, затем 3 целых числа от 0 до 109 - число, месяц и год его рождения, целое число от 0 до 109 - балл студента, целое число k от 0 до 200 - количество университетов, в которые абитуриент готов поступать, и k названий университетов из списка в первой части входа.

Формат вывода
Для каждого университета в алфавитном порядке выведите его название, затем через табуляцию - имена и фамилии поступивших в него студентов, отсортированных по фамилии, имени и дате рождения.



#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


struct Student {
    string name;
    string s_name;
    int d;
    int m;
    int y;
    int mark;
    vector<string> pref;
};


int main() {
    int n;
    cin >> n;
    map<string, int> univer;
    map<string, vector<Student>> st_in_un;
    for (int i = 0; i < n; i++) {
        string u;
        int num;
        cin >> u >> num;
        univer[u] = num;
        st_in_un[u] = {};
    }
    int k;
    cin >> k;
    vector<Student> st(k);
    for (int i = 0; i < k; i++) {
        cin >> st[i].name >> st[i].s_name;
        cin >> st[i].d >> st[i].m >> st[i].y;
        cin >> st[i].mark;
        int q;
        cin >> q;
        for (size_t j = 0; j < q; j++) {
            string un;
            cin >> un;
            st[i].pref.push_back(un);
        }
    }
    sort(st.begin(), st.end(), [](
            const Student& a,
            const Student& b
            ){
        if (a.mark != b.mark) {
            return a.mark > b.mark;
        } else if (a.y != b.y) {
            return a.y < b.y;
        } else if (a.m != b.m) {
            return a.m < b.m;
        } else if (a.d != b.d) {
            return a.d < b.d;
        } else if (a.s_name != b.s_name) {
            return a.s_name < b.s_name;
        } else {
            return a.name < b.name;
        }
    });
    for (const auto& s : st) {
        for (const auto& u : s.pref) {
            if (univer[u] > 0) {
                univer[u]--;
                st_in_un[u].push_back(s);
                break;
            }
        }
    }
    for (auto& [key, val] : st_in_un) {
        cout << key;
        sort(val.begin(), val.end(), [](
                const Student& a,
                const Student& b){
            if (a.s_name != b.s_name) {
                return a.s_name < b.s_name;
            } else if (a.name != b.name) {
                return a.name < b.name;
            } else if (a.y != b.y) {
                return a.y < b.y;
            } else if (a.m != b.m) {
                return a.m < b.m;
            } else {
                return a.d < b.d;
            }
        });
        for (const auto& s : val) {
            cout << '\t' << s.name << " " << s.s_name;
        }
        cout << '\n';
    }
    return 0;
}
