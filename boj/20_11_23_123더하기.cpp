#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *arr = new int[n + 1];
        //초기 항
        arr[1] = 1;  arr[2] = 2;  arr[0] = 1;

        //점화식
        for (int i = 3; i <= n; i++)
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
            
        cout << arr[n] << endl;
    }
}