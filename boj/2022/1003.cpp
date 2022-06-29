//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;
int dp[41][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 40; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    while (T--) {
        int N;
        cin >> N;
        cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }
}