#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int input[8][8], temp[8][8]; //# = -10
int version[6][4] = {        //0 빼고 모두 순회, 얻어진 값 +1 % 4 하면서 4번 실행
    {0, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 3, 0, 0},
    {1, 2, 0, 0},
    {1, 2, 4, 0},
    {1, 2, 3, 4}};
int N, M, answer = 987654;
vector<pair<int, int>> camera;

void paint(int i, int j, int change, int vers)
{

    while (i >= 0 && j >= 0 && i < N && j < M)
    {
        if (temp[i][j] == 6)
            break;
        if (temp[i][j] < 1 || temp[i][j] > 6)
        {
            temp[i][j] += vers;
        }
        i += dy[change], j += dx[change];
    }
}
void recur(int cameraIdx)
{
    if (cameraIdx == camera.size())
    {
        //temp 검사 후 답 갱신, 0 개수 세면 됨
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (temp[i][j] == 0)
                    count++;
        answer = min(answer, count);
        return;
    }
    int herey = camera[cameraIdx].first, herex = camera[cameraIdx].second;
    //version의 첫번째 인덱스
    int vers = input[herey][herex];

    //4번 회전
    for (int i = 0; i < 4; i++)
    {
        //감시 방향 개수
        for (int j = 0; j < 4; j++)
        {
            if (version[vers][j] == 0)
                break;
            //바꿀 dy, dx의 idx
            int change = (version[vers][j] + i) % 4;
            paint(herey, herex, change, 10);
        }
        recur(cameraIdx + 1);
        for (int j = 0; j < 4; j++)
        {

            if (version[vers][j] == 0)
                break;
            //바꿀 dy, dx의 idx
            int change = (version[vers][j] + i) % 4;
            paint(herey, herex, change, -10);
        }
    }
}
int main()
{

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            input[i][j] = c - '0';

            if (c >= '1' && c <= '5')
                camera.push_back({i, j});
        }

    //temp에 memcpy를 먼저 하고, 초기 방향에 따라 감시된 영역을 temp에 저장
    //camera 배열 돌면서 카메라마다 4번 회전 시킨 것 사각지대 검사 - 재귀함수로 구현
    memcpy(temp, input, sizeof(temp));
    recur(0);
    cout << answer << endl;
}
