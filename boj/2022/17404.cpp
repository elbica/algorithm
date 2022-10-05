//
// Created by Kim So Hee on 2022/10/05.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001][3][3], inputs[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i][0] >> inputs[i][1] >> inputs[i][2];
    }

    /**
     * dp[i][color][first] = 1번째 집을 first로 칠했을 때, i번째 color 집까지 최소 비용
     *
     * for first 0 to 2, for color 0 to 2
     * dp[i][color][first] = min (dp[i - 1][another][first] + inputs[i][another])
     *
     * answer
     * min dp[n - 1][red][another] ... 6 case
     *
     * 1번째 집 컬러 정보 저장
     *  - dp 계산을 3번 하는 방법 (1번째 집 색깔 고정, 2번째 집부터 계산)
     */

    dp[0][0][0] = inputs[0][0];
    dp[0][1][1] = inputs[0][1];
    dp[0][2][2] = inputs[0][2];
    dp[0][0][1] = dp[0][0][2] =  dp[0][1][2] =  dp[0][1][0] =  dp[0][2][0] =  dp[0][2][1] = 987654321;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][0][j] = min({dp[i - 1][2][j], dp[i - 1][1][j]}) + inputs[i][0];
            dp[i][1][j] = min({dp[i - 1][2][j], dp[i - 1][0][j]}) + inputs[i][1];
            dp[i][2][j] = min({dp[i - 1][0][j], dp[i - 1][1][j]}) + inputs[i][2];
        }
    }

    cout << min({dp[n - 1][0][1], dp[n - 1][0][2], dp[n - 1][1][0], dp[n - 1][1][2], dp[n - 1][2][1], dp[n - 1][2][0]});
}