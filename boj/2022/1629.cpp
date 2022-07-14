//
// Created by Kim So Hee on 2022/07/13.
//

#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;
ull a, b, c;

ull run(ull number, ull exp) {

    if (exp == 1) return number % c;

    ull ret = run(number, exp / 2);

    if (exp % 2) return ret * ret % c * number % c;
    else return ret * ret % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;

    cout << run(a, b);
}