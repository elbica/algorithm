#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<string> user, ban;
set<string> sets;
bool check[10];

bool matched(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s2[i] == '*')
            continue;
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
void bf(int idx, int count, vector<int> id)
{   //ban[idx], 현재 idx가 user중 동일한 아이디 있는지 검사
    //있으면 그 유저 아이디 string배열에 넣고 재귀호출. bool배열 방문 체크(백트래킹)
    //count==ban.size()일때 string배열 정렬 후 다 합친 string만들어서 set에 저장
    int ret = 0;
    for (int i = 0; i < user.size(); i++)
    {
        //유저 매칭
        if (!check[i] && matched(user[i], ban[idx]))
        {
            if (count + 1 == ban.size())
            {
                id.push_back(i);
                sort(id.begin(), id.end());
                string s = "";
                for (auto z : id)
                    s.push_back('0' + z);
                sets.insert(s);
                continue;
            }
            check[i] = true;
            id.push_back(i);

            bf(idx + 1, count + 1, id);

            check[i] = false;
            id.pop_back();
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    user = user_id;
    ban = banned_id;
    bf(0, 0, vector<int>());

    return sets.size();
}