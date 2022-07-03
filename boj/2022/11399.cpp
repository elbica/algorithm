//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin>>N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        answer += vec[i] * (N-i);
    }
    cout<<answer;

}