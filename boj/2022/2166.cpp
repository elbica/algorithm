//
// Created by Kim So Hee on 2022/09/21.
//

#include <bits/stdc++.h>

using namespace std;

long double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    long double answer = 0;
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = 2; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        // run
        answer += ccw(x1, y1, x2, y2, x, y);
        x2 = x, y2 = y;
    }
    cout << fixed;
    cout.precision(1);
    cout << (round(abs(answer / 2) * 100)) / 100;
}