//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number) {
    if (number == 1)return false;
    if (number == 2 || number == 3) return true;
    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        answer += isPrime((temp));
    }
    cout << answer;
}