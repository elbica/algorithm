//
// Created by Kim So Hee on 2022/07/11.
//

#include <bits/stdc++.h>

using namespace std;


int getD(int number) {
    return (2 * number) % 10000;
}

int getS(int number) {
    return (number + 9999) % 10000;
}

int getL(int number) {
    int d1 = number / 1000;
    return 10 * (number % 1000) + d1;
}

int getR(int number) {
    int d4 = number % 10;
    return d4 * 1000 + number / 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        bool visited[10001]{};

        queue<pair<string, int>> q;


        q.push({"", A});
        visited[A] = true;
        while (!q.empty()) {
            auto here = q.front();
            q.pop();

            if (here.second == B) {
                cout << here.first << '\n';
                break;
            }
            int d = getD(here.second);
            int s = getS(here.second);
            int l = getL(here.second);
            int r = getR(here.second);

            if (!visited[d]) {
                visited[d] = true;
                q.push({here.first + "D", d});
            }
            if (!visited[s]) {
                visited[s] = true;
                q.push({here.first + "S", s});
            }
            if (!visited[l]) {
                visited[l] = true;
                q.push({here.first + "L", l});
            }
            if (!visited[r]) {
                visited[r] = true;
                q.push({here.first + "R", r});
            }

        }
    }
}