//
// Created by Kim So Hee on 2022/07/03.
//

#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 1001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    int n;
    cin >> n;
    cout << dp[n];
}