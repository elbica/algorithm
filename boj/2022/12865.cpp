//
// Created by Kim So Hee on 2022/07/13.
//

#include <bits/stdc++.h>

using namespace std;
int n, k;
int dp[100001];
/**
 * 냅색 알고리즘
 *  1. Fraction Knapsack (Greedy)
 *     물건의 가격을 무게로 나누어, 무게 대비 가격이 비싼 순서로 정렬한다
 *
 *  2. 0-1 Knapsack (DP)
 *     물건을 자를 수 없기 때문에,
 *     무게, 가격, 배낭의 남은 용량을 모두 고려해야 한다
 *
다*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {

        int w, v;
        cin >> w >> v;
        for (int j = k; j >= 0; --j) {
            if (dp[j] && j + w <= k) {
                dp[j + w] = max(dp[j + w], dp[j] + v);
            }
        }
    }

    cout << *max_element(&dp[0], &dp[k + 1]);
}