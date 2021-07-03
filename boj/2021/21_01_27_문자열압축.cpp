#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string input;

bool matched(int i, int j, int k)
{   //문자 비교
    while (k--)
    {
        if (j >= input.size()) return false;
        if (input[i++] != input[j++]) return false;
    }
    return true;
}
int func(int start, int k)
{
    //탐색 끝. 문자열이 남았으면 그 문자열의 길이 반환
    if (start + k >= input.size()) return input.substr(start).size();

    int checkidx = start + k, tempidx = start;
    int nextidx = start + k, count = 0, num;
    while (matched(start, nextidx, k))
    {
        nextidx += k;
        count++;
    }
    //문자열이 몇 번 나왔는지에 따라 앞에 붙일 문자 길이 계산
    if (count == 0) num = 0;
    else if (count < 9) num = 1;
    else if (count < 99) num = 2;
    else if (count < 999) num = 3;

    //점화식
    return k + num + func(nextidx, k);
}
int solution(string s)
{
    int answer = s.size();
    input = s;
    for (int i = 1; i <= s.size()/2; i++) answer = min(answer, func(0, i));
    return answer;
}