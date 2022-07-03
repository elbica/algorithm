//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int dp[12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /**
     * 3 =
     *   3
     *   2 + 1
     *   1 + 2
     *   1 + 1 + 1
     */

    dp[1] = 1, dp[2] = 2, dp[3] = 4;

    int T;
    cin >> T;

    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}