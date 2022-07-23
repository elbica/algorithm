//
// Created by Kim So Hee on 2022/07/17.
//

#include <bits/stdc++.h>

using namespace std;
int inputs[501][501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin>>n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin>>inputs[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + inputs[i][j];
        }
    }

    cout<< *max_element(&dp[n][1], &dp[n][n+1]);

}