//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxdiv(int x, int y) {
    if (x > y) swap(x, y);
    for (int i = x; i > 0; i--)
        if (x % i == 0 && y % i == 0)return i;
}

int main() {
    int x, y;
    cin >> x >> y;
    int maxdiv = getMaxdiv(x, y);
    cout << maxdiv << ' ' << x * y / maxdiv;
}