//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

string check(int a, int b, int c) {
    int checkArray[3];
    checkArray[0] = (int) sqrt(a * a + b * b);
    checkArray[1] = (int) sqrt(a * a + c * c);
    checkArray[2] = (int) sqrt(b * b + c * c);

    bool flag = false;

    for (int check: checkArray) {
        if (check == a || check == b || check == c) flag = true;
    }
    return flag ? "right" : "wrong";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) break;
        cout << check(a, b, c) << '\n';
    }

}