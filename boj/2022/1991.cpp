//
// Created by Kim So Hee on 2022/07/24.
//

#include <bits/stdc++.h>

using namespace std;
char inputs[127][2];

void run(char c, int flag) {
    if (c == '.') return;

    if (flag == -1) cout << c;
    run(inputs[c][0], flag);

    if (flag == 0) cout << c;
    run(inputs[c][1], flag);

    if (flag == 1) cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        cin >> inputs[c][0] >> inputs[c][1];
    }
    run('A', -1);
    cout << '\n';
    run('A', 0);
    cout << '\n';
    run('A', 1);
}