#include <iostream>
#include <algorithm>
using namespace std;

//0 : 현재 잔 안마실 때, 1 : 현재 잔 포함해 연속 1개, 2: 연속 2개
int arr[10001][3];
int input[10001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];
    arr[0][0] = 0;
    arr[0][2] = arr[0][1] = input[0];
    for (int i = 1; i < n; i++)
    {
        arr[i][0] = max(arr[i - 1][0], max(arr[i - 1][1], arr[i - 1][2])); //안 마시기
        arr[i][1] = arr[i - 1][0] + input[i]; //안 마신 상황 + 현재 잔 마시기
        arr[i][2] = arr[i - 1][1] + input[i]; //한 잔만 마신 상황 + 현재 잔 마시기
    }
    cout << max(arr[n - 1][0], max(arr[n - 1][1], arr[n - 1][2])) << endl;
}