#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//부분 일치 테이블 계산
vector<int> getPartialMatch(const string &N)
{
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m)
    {
        if (N[begin + matched] == N[matched])
        {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
                ++begin;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main()
{
    //두번 이상 나오는 문자열 => 일치하는 접미사와 접두사
    string s, temp;
    cin >> s;
    vector<int> arr;
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        temp = s.substr(i); //문자열을 s[i]부터 끝까지 자르고
        arr = getPartialMatch(temp); //부분 일치 테이블을 얻는다

        //부분 일치 테이블의 최대 값이 가장 긴 문자열의 길이이다
        answer = max(answer, *max_element(arr.begin(), arr.end()));
    }
    cout << answer << endl;
}