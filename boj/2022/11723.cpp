//
// Created by Kim So Hee on 2022/07/01.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> mySet;
    int M;
    cin >> M;
    while (M--) {
        string s;
        int n;
        cin >> s;
        /**
         * 비트 연산자로 대체 가능하다!
         */
        if (s == "add") {
            cin >> n;
            mySet.insert(n);
        } else if (s == "remove") {
            cin >> n;
            mySet.erase(n);
        } else if (s == "check") {
            cin >> n;
            cout << mySet.count(n) << '\n';
        } else if (s == "toggle") {
            cin >> n;
            bool isExist = mySet.count(n);
            if (isExist) {
                mySet.erase(n);
            } else {
                mySet.insert(n);
            }
        } else if (s == "all") {
            for (int i = 1; i <= 20; ++i) {
                mySet.insert(i);
            }
        } else if (s == "empty") {
            mySet.clear();
        }
    }

}