//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int M;
    unordered_set<int> inputSet;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        inputSet.insert(temp);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int temp;
        cin >> temp;
        cout << inputSet.count(temp) << '\n';
    }
}