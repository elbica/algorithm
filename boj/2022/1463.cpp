//
// Created by Kim So Hee on 2022/06/30.
//

#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(arr, arr + MAX, 987654321);
    arr[1] = 0;

    arr[2] = arr[3] = 1;
    for (int i = 4; i < MAX; i++) {
        bool divTwo = i % 2 == 0;
        bool divThree = i % 3 == 0;

        arr[i] = arr[i - 1] + 1;
        if (divTwo) arr[i] = min(arr[i], arr[i / 2] + 1);
        if (divThree) arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    int N;
    cin >> N;
    cout << arr[N];
}