#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    string st;
    cin >> st;
    char c; //cin >> c; s.push(c);
    int answer = 0, idx = 0;
    s.push(st[0]);
    bool conti = false;
    while (idx < st.size())
    {
        c = st[++idx];
        if (c == ')')
        {
            s.pop();
            answer += s.size();
            //cout << answer << endl;
            //s.pop();
            if (conti)
            {
                answer -= s.size() - 1;
            }
            conti = true;
        }
        else
        {
            conti = false;
            //count++;
            s.push(c);
        }
        //cout << count << endl;
    }
    cout << answer << endl;
}