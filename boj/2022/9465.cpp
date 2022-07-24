//
// Created by Kim So Hee on 2022/07/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int dp[100001][2]{};
        int inputs[100001][2]{};
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> inputs[i][0];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> inputs[i][1];
        }

        dp[1][0] = inputs[1][0];
        dp[1][1] = inputs[1][1];

        for (int i = 2; i <= n; ++i) {
            // max(dp[i - 2][1], dp[i - 1][1]) + inputs[i][0] 이 올바른 점화식이다.
            // dp[i - 2][0]은 dp[i - 1][1]에 포함 되어 있기 때문이다.
            dp[i][0] = max(max(dp[i - 2][0], dp[i - 2][1]), dp[i - 1][1]) + inputs[i][0];
            dp[i][1] = max(max(dp[i - 2][0], dp[i - 2][1]), dp[i - 1][0]) + inputs[i][1];
        }
        cout << max(dp[n][0], dp[n][1]) << '\n';
    }

}