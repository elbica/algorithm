//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

#define MAX 10001

using namespace std;
int startPtr = 0, endPtr = -1;

bool isEmpty() {
    if (startPtr - 1 == endPtr) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num;
    cin >> num;
    deque<int> dq;
    queue<int> answer;

    for(int i=0; i < num; i++)
    {
        string temp;
        cin >> temp;
        if(temp == "push_front")
        {
            int tmp;
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if(temp == "push_back")
        {
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if(temp == "pop_front")
        {
            if(dq.empty())
                answer.push(-1);
            else
            {
                answer.push(dq.front());
                dq.pop_front();
            }
        }
        else if(temp == "pop_back")
        {
            if(dq.empty())
                answer.push(-1);
            else
            {
                answer.push(dq.back());
                dq.pop_back();
            }
        }

        else if(temp == "size")
            answer.push(dq.size());

        else if(temp == "empty")
            answer.push(dq.empty());
        else if(temp == "front")
        {
            if(dq.empty())
                answer.push(-1);
            else
                answer.push(dq.front());
        }

        else if(temp == "back")
        {
            if(dq.empty())
                answer.push(-1);
            else
                answer.push(dq.back());
        }
    }
    // 출력
    while (!answer.empty())
    {
        cout << answer.front() << '\n';
        answer.pop();
    }

}