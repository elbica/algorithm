//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int main() {
    vector<string> vec;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end(), comp);
    auto uniquePoint = unique(vec.begin(), vec.end());
    vec.erase(uniquePoint, vec.end());

    for (const auto& v: vec) cout << v << '\n';
}