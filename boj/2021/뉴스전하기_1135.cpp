#include <bits/stdc++.h>
using namespace std;

/* 
    부하들 중 max 값 + 1 = 현재 직원
    부하가 없으면 그 직원 값 0
*/
int N;
vector<int> adj[51]; //index = 상사, 값 = 부하들

//현재 직원에서 전화를 돌릴 때 걸리는 총 시간
int getTime(int cur)
{
    if (adj[cur].size() == 0)
        return 0;

    int ret = -1;
    vector<int> temp;

    for (int i = 0; i < adj[cur].size(); i++)
    {
        temp.push_back(getTime(adj[cur][i]));
    }

    /*
        부하 직원들의 걸린 시간을 내림차순으로 정렬 후
        가중치를 더한 값을 max처리

    */
    sort(temp.rbegin(),temp.rend());
    for(int i=0; i<temp.size(); i++) ret = max(temp[i]+i+1,ret);

    return ret;
}


int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int admin;
        cin >> admin;
        if (admin == -1)
            continue;
        adj[admin].push_back(i);
    }
    cout << getTime(0) << endl;
}