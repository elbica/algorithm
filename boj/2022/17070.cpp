//
// Created by Kim So Hee on 2022/08/04.
//

#include <bits/stdc++.h>

using namespace std;

enum MOVE {
    V, H, D
};

int N;
bool inputs[17][17];
int dp[17][17][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> inputs[i][j];
        }
    }
    dp[1][2][MOVE::H] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 3; j <= N; ++j) {
            if (inputs[i][j]) continue;
            dp[i][j][MOVE::H] = dp[i][j - 1][MOVE::H] + dp[i][j - 1][MOVE::D];
            dp[i][j][MOVE::V] = dp[i - 1][j][MOVE::V] + dp[i - 1][j][MOVE::D];

            if (inputs[i - 1][j] || inputs[i][j - 1]) continue;
            dp[i][j][MOVE::D] = dp[i - 1][j - 1][MOVE::H] + dp[i - 1][j - 1][MOVE::V] + dp[i - 1][j - 1][MOVE::D];
        }
    }
    cout << dp[N][N][MOVE::H] + dp[N][N][MOVE::V] + dp[N][N][MOVE::D];
}