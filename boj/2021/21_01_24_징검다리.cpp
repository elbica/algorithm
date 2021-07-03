#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0;
    vector<pair<int, int>> input;
    for (int i = 0; i < stones.size(); i++)
    {
        input.push_back({stones[i], i}); //돌 값, 돌 번호
    }
    sort(input.begin(), input.end());
    int uf[200000], ufSize[200000] = {};
    bool check[200000] = {};
    for (int i = 0; i < stones.size(); i++)
        uf[i] = i;

    for (auto i : input)
    {
        int here = i.second;
        bool left = 0, right = 0;
        if (here > 0)
            left = check[here - 1];
        if (here < stones.size() - 1)
            right = check[here + 1];
        check[here] = true;
        if (!left && !right)
        {
            ufSize[here] = 1;
            if (ufSize[uf[here]] >= k)
            {
                answer = i.first;
                break;
            }
        }
        else if (left && right)
        {
            uf[here] = uf[here - 1]; //왼쪽 루트 가져옴
            //here의 오른쪽 칸들의 루트 왼쪽루트로 변경
            int j = here + 1;
            int temp = uf[j];
            ufSize[uf[here]] += (1 + ufSize[uf[j]]);
            while (uf[j] == temp)
                uf[j++] = uf[here];

            if (ufSize[uf[here]] >= k)
            {
                answer = i.first;
                break;
            }
        }
        else
        { //하나만 있는 경우
            bool flag = left ? left : right;
            int idx = left ? here - 1 : here + 1;
            uf[here] = uf[idx];
            ufSize[uf[here]]++;
            if (ufSize[uf[here]] >= k)
            {

                answer = i.first;
                break;
            }
        }
    }
    return answer;
}