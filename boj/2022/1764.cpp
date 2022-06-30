//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    unordered_set < string > name;
    vector<string> answer;
    int N, M;
    cin >> N >> M;
    while (N--) {
        string s;
        cin >> s;
        name.insert(s);
    }
    while (M--) {
        string s;
        cin >> s;
        if (name.count(s)) answer.push_back(s);
    }

    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());

    for (const auto &item: answer) {
        cout << item << '\n';
    }
}