#include <iostream>
using namespace std;
//자료형 주의
long long arr[91][2];

int main()
{
    int n;
    cin >> n;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 1][1];

        //1이 연속 두번 나오면 안 된다
        arr[i][1] = arr[i - 1][0];
    }
    cout << arr[n][0] + arr[n][1] << endl;
}