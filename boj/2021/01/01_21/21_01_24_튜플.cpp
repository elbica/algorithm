#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}
*/
bool check[100001];
bool compare(string s1, string s2)
{ // 알아서 2개씩 꺼내서 비교함
    if (s1.size() == s2.size())
    { //사이즈가 같으면, 사전순 앞으로.
        return s1 < s2;
    }

    return s1.size() < s2.size(); // 내림차순 정렬
    //return s1 > s2; // 오름차순 정렬
}
vector<int> solution(string s)
{
    vector<int> answer;
    vector<string> sets;
    string data = s.substr(2, s.size() - 3), token;
    stringstream ss(data);

    while (getline(ss, token, '}'))
    {
        sets.push_back(token);
    }
    sort(sets.begin(), sets.end(), compare);

    for (auto s : sets)
        cout << s << "..." << endl;
    vector<vector<int>> inputs(sets.size());
    for (int i = 0; i < sets.size(); i++)
    {

        stringstream ss(sets[i]);
        string token;
        while (getline(ss, token, ','))
        {
            if (token[0] == '{')
                token = token.substr(1);
            if (token.size() == 0)
                continue;
            inputs[i].push_back(stoi(token));
        }
    }
    sort(inputs.begin(), inputs.end());
    for (int i = 0; i < inputs.size(); i++)
    {
        for (int j = 0; j < inputs[i].size(); j++)
            cout << inputs[i][j] << '/';
        cout << endl;
    }
    //input[i][j]에 아무것도 없을 수 잇음. 사이즈 체크
    for (int i = 0; i < inputs.size(); i++)
    {
        for (int j = 0; j < inputs[j].size(); j++)
        {

            if (!check[inputs[i][j]])
            {
                check[inputs[i][j]] = true;
                answer.push_back(input[i][j]);
                break;
            }
        }
    }
    return answer;
}