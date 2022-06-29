//
// Created by Kim So Hee on 2022/06/29.
//

#include <bits/stdc++.h>

using namespace std;

bool comp(tuple<int, string, int> left, tuple<int, string, int> right) {
    int leftAge = get<0>(left);
    int rightAge = get<0>(right);
    int leftOrder = get<2>(left);
    int rightOrder = get<2>(right);

    if (leftAge == rightAge) {
        return leftOrder < rightOrder;
    }
    return leftAge < rightAge;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    /*
     * @description
     *
     *  vector 2차원으로 선언하면
     *  굳이 tuple로 묶지 않아도
     *  age는 vector의 인덱스로 처리하면 된다
     *  정렬도 안해도 된다!
     *
     * */
    vector<tuple<int, string, int>> vec;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        vec.emplace_back(age, name, i);
    }
    sort(vec.begin(), vec.end(), comp);

    for (auto v: vec) {
        cout << get<0>(v) << ' ' << get<1>(v) << '\n';
    }
}