Известная утилита word2vec, основанная на нейронной сети, умеет приписывать каждому слову из словаря некоторый числовой вектор размерности N. При этом оказывается, что семантически «близким» словам соответствуют «близкие» векторы. Эта утилита находит широкое применение в задачах обработки естественного языка и машинного обучения.

В качестве меры «близости» между словами обычно выбирают угол между их векторами, косинус которого вычисляют по известной формуле


Однако часто векторы слов нормируют (чтобы их длина стала равна константе), и тогда в качестве меры близости рассматривают просто скалярное произведение


Чем это скалярное произведение больше, тем семантически «ближе» слова друг к другу.

Вам дан словарь из M слов, каждому из которых сопоставлен N-мерный вектор. Гарантируется, что все слова различны. Требуется найти в этом списке ближайшие слова к первому слову (кроме самого этого первого слова), используя в качестве метрики близости просто скалярное произведение.

Формат ввода
В первой строке через пробел записано 2 целых числа — M (2 ≤ M ≤ 100) и N (3 ≤ N ≤ 1000) — количество слов в словаре и размерность векторов соответственно.

Далее следует M строк, каждая из которых описывает очередное слово. Описание состоит из самого слова, длиной не более 15 символов, состоящего из строчных латинских букв, и набора из N целых чисел, разделенных пробелами. Компоненты вектора по модулю не превосходят 1000.

Формат вывода
Выпишите слова (по одному на строке), скалярное произведение векторов которых с вектором первого слова максимально. При этом скалярное произведение первого слова с самим собой учитывать не нужно. Если таких слов несколько, то их следует вывести в том же порядке, в котором они были даны на входе.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> vec(m);
    for (size_t i = 0; i < m; i++) {
        cin >> vec[i];
    }
    vector<pair<string, int>> mp;
    int maxx = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        int t = 0;
        string ss;
        cin >> ss;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            t += vec[j] * x;
        }
        mp.push_back({ss, t});
        if (t > maxx) {
            maxx = t;
        }
    }
    for(const auto& [key, val] : mp) {
        if (val == maxx) {
            cout << key << "\n";
        }
    }
    return 0;
}