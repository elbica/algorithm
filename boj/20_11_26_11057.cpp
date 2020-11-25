#include <iostream>
#define DIV 10007
using namespace std;
int arr[1000][10];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
        arr[0][i] = 1;

    //점화식 : N번째 자리가 i인 경우의 수 = 
    //          N-1번째 자리가 0 ~ i인 경우의 수 더함
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++)
            {
                arr[i][j] += arr[i - 1][k];
                arr[i][j] %= DIV;
            }
    int answer = 0;
    for (int i = 0; i <= 9; i++)
    {
        answer += arr[n - 1][i];
        answer %= DIV;
    }
    cout << answer;
}