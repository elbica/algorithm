#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
    cin >> s;
    stringstream ss(s);
    string token;
    vector<string> inputs;
    while (getline(ss, token, '-'))
    {
        inputs.push_back(token);
    }
    int answer = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        stringstream ss(inputs[i]);
        string token;
        while (getline(ss, token, '+'))
        {
            if (i != 0)
                answer -= stoi(token);
            else
                answer += stoi(token);
        }
    }
    cout << answer;
}