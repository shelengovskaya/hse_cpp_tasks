Будильник в сотовом телефоне можно настроить так, чтобы он звонил каждый день в одно и то же время, либо в указанное время в определенный день недели. Независимо можно настроить несколько будильников. По информации о будильниках и текущему времени и дню недели определите, когда прозвонит очередной будильник.

Формат ввода
В первой строке вводятся три числа, задающие текущее время: день недели (от 1 до 7), часы и минуты. Во второй строке вводится одно натуральное число N, не превосходящее 100 – количество будильников. В следующих N строках вводятся описания N будильников. Описание каждого будильника состоит из трех чисел: дня недели (число от 1 до 7 для понедельника,  …, воскресенья, соответственно, 0 – если будильник должен звонить каждый день), часов (от 0 до 23), минут (от 0 до 59).

Формат вывода
Выведите  через пробел три числа, задающие день недели, часы и минуты, когда прозвонит ближайший будильник.

#include <iostream>


using namespace std;


int main() {
    const int week = 7 * 24 * 60;
    int d0, h0, min0, n, diff = 7 * 24 * 60 + 1;
    cin >> d0 >> h0 >> min0 >> n;
    int c = (d0 - 1) * 24 * 60 + h0 * 60 + min0;
    for (int i = 0; i < n; ++i) {
        int d1, h1, m1, x;
        cin >> d1 >> h1 >> m1;
        if (d1 != 0) {
            if (c > (d1 - 1) * 24 * 60 + h1 * 60 + m1) {
                x = week - (c - ((d1 - 1) * 24 * 60 + h1 * 60 + m1));
            } else {
                x = (d1 - 1) * 24 * 60 + h1 * 60 + m1 - c;
            }
        } else {
            if (h1 < h0) {
                d1 = d0 % 7 + 1;
            } else if (h1 == h0 && m1 < min0) {
                d1 = d0 % 7 + 1;
            } else if (h1 == h0 && m1 >= min0) {
                d1 = d0;
            } else if (h1 >= h0) {
                d1 = d0;
            }
            if (c > (d1 - 1) * 24 * 60 + h1 * 60 + m1) {
                x = week - (c - ((d1 - 1) * 24 * 60 + h1 * 60 + m1));
            } else {
                x = (d1 - 1) * 24 * 60 + h1 * 60 + m1 - c;
            }
        }
        diff = min(diff, x);
    }
    c += diff;
    int ans1 = c / (60 * 24);
    c %= (60 * 24);
    int ans2 = c / 60;
    int ans3 = c % 60;
    cout << ans1 % 7 + 1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}

