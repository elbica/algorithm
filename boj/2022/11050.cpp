//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K; cin>>N>>K;
    long long upper = 1;
    long long lower = 1;

    for (int i = 1; i <= K; ++i) {
        lower *= i;
        upper *= (N-i+1);
    }
    cout<<upper/lower;

}