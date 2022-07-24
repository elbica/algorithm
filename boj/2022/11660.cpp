//
// Created by Kim So Hee on 2022/07/24.
//

#include <bits/stdc++.h>

using namespace std;

int inputs[1025][1025], cal[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> inputs[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cal[i][j] = inputs[i][j] + cal[i - 1][j] + cal[i][j - 1] - cal[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << cal[y2][x2] - cal[y2][x1 - 1] - cal[y1 - 1][x2] + cal[y1 - 1][x1 - 1] << '\n';
    }

}