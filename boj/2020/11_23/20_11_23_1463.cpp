#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;
//점화식 : N -> N/3, N/2, N-1 중 최소값 + 1
//바텀 업

int main()
{
    int N;
    cin >> N;
    int *arr = new int[3 * N + 1];
    for (int i = 0; i < 3 * N + 1; i++)
        arr[i] = MAX;

    arr[1] = 0; //초기 항
    for (int i = 1; i < N; i++)
    {
        arr[i + 1] = min(arr[i + 1], arr[i] + 1);
        arr[2 * i] = min(arr[2 * i], arr[i] + 1);
        arr[3 * i] = min(arr[3 * i], arr[i] + 1);
    }
    cout << arr[N] << endl;
}