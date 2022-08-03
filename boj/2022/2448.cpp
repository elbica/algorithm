//
// Created by Kim So Hee on 2022/08/03.
//

#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> answer;

void divide(int y, int x, int width) {
    if (width == 6) {
        for (int i = 0; i < width - 1; i++) {
            answer[y][x - i - 1] = '*';
        }
        answer[y - 1][x - 2] = answer[y - 1][x - 4] = '*';
        answer[y - 2][x - 3] = '*';
        return;
    }

    int next = width / 2;
    divide(y, x - next, next);
    divide(y, x, next);
    divide(y - next / 2, x - next / 2, next);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    answer.resize(n, string(2 * n, ' '));

    divide(n - 1, 2 * n - 1, 2 * n);
    for (const auto &a: answer) {
        cout << a << "\n";
    }
}