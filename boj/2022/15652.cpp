//
// Created by Kim So Hee on 2022/08/03.
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> answer;

void recur(int number, int depth) {
    if (depth == m) {
        for (const auto &a: answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = number; i <= n; i++) {
        answer[depth] = i;
        recur(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    answer.resize(m);
    recur(1, 0);
}