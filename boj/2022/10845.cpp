//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin>>N;
    int* que = new int[N+1];
    int start = 0, end = -1;
    while(N--){
        string command;
        cin >> command;
        if (command == "push") {
            int number;
            cin >> number;
            que[++end] = number;
        } else if (command == "pop") cout << (start > end ? -1 : que[start++]) << '\n';
        else if (command == "size") cout << end-start+1 << '\n';
        else if (command == "empty") cout << (start > end ? 1 : 0) << '\n';
        else if (command == "front") cout << (start <=end ? que[start] : -1) << '\n';
        else if (command == "back") cout << (start <=end ? que[end] : -1) << '\n';
    }

}