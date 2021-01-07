#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100000][3];
int input[2][100000];

int main()
{
    cin.tie(NULL);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> input[i][j];
        arr[0][0] = input[0][0];
        arr[0][1] = input[1][0];
        arr[0][2] = 0;

        for (int i = 1; i < n; i++)
        {   //경우   : 1. input[i][0]을 선택하는 경우
            //         2. input[i][1]을 선택하는 경우
            //         3. 둘 다 선택하지 않는 경우
            arr[i][0] = max(arr[i - 1][1], arr[i - 1][2]) + input[0][i];
            arr[i][1] = max(arr[i - 1][0], arr[i - 1][2]) + input[1][i];
            arr[i][2] = max(arr[i - 1][0], arr[i - 1][1]);
        }

        cout << max(arr[n - 1][0], max(arr[n - 1][1], arr[n - 1][2])) << '\n';
    }
}