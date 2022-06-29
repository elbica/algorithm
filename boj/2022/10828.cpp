//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;
int stk[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    int ptr = -1;
    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int number;
            cin >> number;
            stk[++ptr] = number;
        } else if (command == "pop") cout << (ptr == -1 ? -1 : stk[ptr--]) << '\n';
        else if (command == "size") cout << ptr + 1 << '\n';
        else if (command == "empty") cout << (ptr == -1 ? 1 : 0) << '\n';
        else if (command == "top") cout << (ptr != -1 ? stk[ptr] : -1) << '\n';
    }

}