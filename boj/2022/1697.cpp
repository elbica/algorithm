//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(dp, dp + 100001, 987654321);

    int N, K;
    cin >> N >> K;
    dp[N] = 0;
    queue<int> start;

    start.push(N);
    while (!start.empty()) {
        int here = start.front();
        start.pop();
        int nextArray[3] = {here - 1, here + 1, 2 * here};

        /**
         * @details
         *   bfs로 방문하는 지점들은 항상 최단거리이다.
         *   굳이 if로 대소 비교 안해도.. 방문 여부만 체크해 주면 된다
         */
        for (const auto &next: nextArray) {
            if (next < 0 || next > 100000 || dp[next] != 987654321) continue;
                dp[next] = dp[here] + 1;
                start.push(next);
        }
    }
    cout << dp[K];

}