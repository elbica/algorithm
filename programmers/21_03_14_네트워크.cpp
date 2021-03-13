#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    bool visited[222] = {};

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        queue<int> q;
        q.push(i);
        answer++;
        while (!q.empty())
        {
            int here = q.front();
            q.pop();
            if (visited[here])
                continue;
            visited[here] = true;
            for (int k = 0; k < n; k++)
            {
                if (k == here)
                    continue;
                q.push(k);
            }
        }
    }

    return answer;
}