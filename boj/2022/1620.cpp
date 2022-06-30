//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;

    unordered_map<string, string> myMap;

    for (int i = 1; i <= N; i++) {
        string poketmon;
        cin >> poketmon;
        /**
         *  1. 이름은 모두 영어
         *  2. 첫 글자는 대문자
         *  3. 마지막 문자 대문자일 수도 있음
         *  4. 길이는 2 ~ 20
         *
         *  사용 자료구조 : map
         *
         */
        myMap[poketmon] = to_string(i);
        myMap[to_string(i)] = poketmon;

    }
    while (M--) {
        string s;
        cin >> s;
        cout << myMap[s] << '\n';
    }
}