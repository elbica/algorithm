//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    for (auto v: vec) {
        cout << v.first << ' ' << v.second << '\n';
    }
}