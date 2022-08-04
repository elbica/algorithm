//
// Created by Kim So Hee on 2022/08/05.
//

#include <bits/stdc++.h>

using namespace std;

set<vector<int>> answer;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> inputs(n);

    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }
    std::sort(inputs.begin(), inputs.end());
    do {
        vector<int> temp;
        for (int i = 0; i < m; ++i) {
            temp.push_back(inputs[i]);
        }
        answer.insert(temp);
    } while (std::next_permutation(inputs.begin(), inputs.end()));
    for (const auto &a: answer) {
        for (const auto &number: a) {
            cout << number << ' ';
        }
        cout << '\n';
    }
}