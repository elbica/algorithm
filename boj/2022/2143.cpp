//
// Created by Kim So Hee on 2022/10/03.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;
    long long answer = 0;
    cin >> t >> n;
    vector<int> a(n), sumA(n + 1), genA;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sumA[i + 1] = sumA[i] + a[i];
    }
    cin >> m;
    vector<int> b(m), sumB(m + 1), genB;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sumB[i + 1] = sumB[i] + b[i];
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            genA.push_back(sumA[i] - sumA[j]);
        }
    }
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            genB.push_back(sumB[i] - sumB[j]);
        }
    }

    std::sort(genB.begin(), genB.end());
    for (const auto &sum: genA) {
        answer += std::upper_bound(genB.begin(), genB.end(), t - sum) -
                  std::lower_bound(genB.begin(), genB.end(), t - sum);
    }

    cout << answer;

}