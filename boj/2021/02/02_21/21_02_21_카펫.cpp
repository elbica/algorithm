#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    vector<pair<int, int>> temp;
    int all = brown + yellow;
    for (int i = 1; i <= pow(brown, 0.5); i++)
    {
        if (brown % i == 0)
            temp.push_back({i, brown / i});
    }
    for (int i = 1; i <= pow(yellow, 0.5); i++)
    {
        if (yellow % i == 0)
            temp.push_back({i, yellow / i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            answer.push_back(temp[i].second);
            answer.push_back(temp[i].first);
        }
    }
    return answer;
}