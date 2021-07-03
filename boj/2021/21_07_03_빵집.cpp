#include <bits/stdc++.h>
using namespace std;
char input[10001][501];
bool check[10001][501];

int dy[3] = {-1, 0, 1};
int answer = 0;
int R, C;

bool dfs(int y, int x)
{
    //현재 좌표 : (y,x)
    //기저1 : 장애물 만났을 때
    if (input[y][x] == 'x')
        return false;
    //기저2 : 방문된 경우
    if (check[y][x])
        return false;

    check[y][x] = true;
    //기저3 : 도달 한 경우
    if (x == C - 1)
    {
        answer++;
        return true;
    }

    int nextX = x + 1, nextY;

    for (int i = 0; i < 3; i++)
    {
        nextY = y + dy[i];
        //범위 체크 및 방문 체크
        if (nextY < 0 || nextY >= R)
            continue;

        if (dfs(nextY, nextX))
            return true;
    }
    //더 이상 연결 못 하는 경우
    // check[y][x] = false;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> input[i][j];

    for (int i = 0; i < R; i++)
        dfs(i, 0);

    cout << answer;
}