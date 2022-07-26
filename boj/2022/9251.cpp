//
// Created by Kim So Hee on 2022/07/25.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    int dp[1001][1001]{};

    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout<<dp[s1.size()][s2.size()];
}