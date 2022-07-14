//
// Created by Kim So Hee on 2022/07/13.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int inputs[1001], dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> inputs[i];
    }

    for (int i = 1; i <= n; ++i) {
        int temp = 0;
        for (int j = 1; j < i; ++j) {
            if (temp < dp[j] && inputs[i] > inputs[j]) temp = dp[j];
        }
        dp[i] = temp + 1;
    }
    cout << *max_element(&dp[0], &dp[n + 1]);
}