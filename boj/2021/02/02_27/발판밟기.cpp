#include <bits/stdc++.h>
int n;
using namespace std;
vector<int> input;
int answer = 0;
void recur(int idx, int count, bool arr[])
{

    //idx번째를 밟기 전에 밟은 개수 : count
    if (arr[idx])
    { //이미 밟아져 있는 경우
        answer = max(answer, count + 1);
        return;
    }
    arr[idx] = true;
    int nextidx = (idx + input[idx]);
    if (nextidx < 0 || nextidx >= n)
    {
        //인덱스 아웃
        answer = max(answer, count);
        return;
    }
    recur(nextidx, count + 1, arr);
}
int main()
{

    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    bool arr[101] = {};
    recur(0, 0, arr);

    recur(1, 0, arr);
    recur(2, 0, arr);
    cout << answer;
}