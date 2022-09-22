//
// Created by Kim So Hee on 2022/09/22.
//

#include <bits/stdc++.h>

using namespace std;
vector<int> inputs;
int n, s, answer;

void recur(int index, int sum) {
    if (index == n) return;

    if (sum + inputs[index] == s) answer++;
    recur(index + 1, sum + inputs[index]);
    recur(index + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;

    inputs.resize(n);
    for (int i = 0; i < n; ++i) cin >> inputs[i];
    std::sort(inputs.begin(), inputs.end());

    /**
     * 2의 20승 = 약 1,000,000
     */
    recur(0, 0);
    cout << answer;
}