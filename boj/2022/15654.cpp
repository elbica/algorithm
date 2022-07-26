//
// Created by Kim So Hee on 2022/07/25.
//

#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<int> inputs;
int n, m;

void print(vector<int> perm, int depth) {
    if (depth == m) {
        for (const auto &p: perm) {
            cout << p << ' ';
        }
        cout << '\n';
        return;
    }

    for (const auto &input: inputs) {
        if (!visited[input]) {
            visited[input] = true;
            perm.push_back(input);
            print(perm, depth + 1);
            perm.pop_back();
            visited[input] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    inputs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }
    std::sort(inputs.begin(), inputs.end());
    print(vector<int>(), 0);
}