//
// Created by Kim So Hee on 2022/07/17.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> combination(n, false);
    for (int i = 0; i < m; ++i) {
        combination[i] = true;
    }
    do {
        for (int i = 0; i < combination.size(); ++i) {
            if (combination[i]) cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (prev_permutation(combination.begin(), combination.end()));

}