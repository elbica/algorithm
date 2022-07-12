//
// Created by Kim So Hee on 2022/07/12.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int inputs[1001][3];
int dp[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i][0] >> inputs[i][1] >> inputs[i][2];
    }

    dp[0][0] = inputs[0][0];
    dp[0][1] = inputs[0][1];
    dp[0][2] = inputs[0][2];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + inputs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + inputs[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + inputs[i][2];
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}