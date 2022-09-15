//
// Created by Kim So Hee on 2022/09/16.
//

#include <bits/stdc++.h>

using namespace std;
int dp[2001][2001]{};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) cin >> inputs[i];

    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][i] = 1;
        if (inputs[i] == inputs[i - 1]) dp[i - 1][i] = 1;
    }
    for (int offset = 2; offset < n; ++offset) {
        for (int start = 0; start < n; ++start) {
            if (start + offset >= n) break;
            if (dp[start + 1][start + offset - 1] && inputs[start] == inputs[start + offset]) {
                dp[start][start + offset] = 1;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        cout << dp[--s][--e] << '\n';
    }
}