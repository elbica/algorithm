#include <iostream>
#include <vector>
#define DIV 1000000000
using namespace std;

//arr[n][i] = n번째 숫자가 i일 때의 경우의 수
int arr[101][11];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
        arr[1][i] = 1; //초기 항

    //점화식 : arr[n][i] = arr[n-1][i-1] + arr[n-1][i+1]
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (j > 0)
            {
                arr[i][j] += arr[i - 1][j - 1];
                arr[i][j] %= DIV;
            }

            arr[i][j] += arr[i - 1][j + 1];
            arr[i][j] %= DIV;
        }
    int answer = 0;
    for (int i = 0; i <= 9; i++)
    {
        answer += arr[n][i];
        answer %= DIV;
    }
    cout << answer << endl;
}