//
// Created by Kim So Hee on 2022/08/01.
//

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> inorder, postorder;
int inorderIdx[100001];

void divide(int pStart, int pEnd, int iStart, int iEnd) {

    /**
     * 후위 순회의 특징은 맨 뒤 원소가 트리의 루트인 것이다.
     *  - 루트 원소를 출력한다.
     *  - 구간 길이가 1인 경우 종료한다.
     *
     * 루트 원소 기준으로 중위 순회의 left, right 구간을 나눈다.
     *  - 중위 원소의 left, right 구간을 후위 순회에 대입해 루트를 다시 찾는다.
     *  - 구간의 길이를 사용 한다.
     */
    if (pStart > pEnd) return;
    cout<< postorder[pEnd]<<' ';

    /**
     * 인덱스를 찾기 위해 for문을 돌고 있다..
     * 입력 시 인덱스도 같이 매핑 한다면 for 순회를 안해도 된다.

    for (int i = iStart; i <= iEnd; ++i) {
        if (inorder[i] == postorder[pEnd]) {
            int length = i - iStart;

            divide(pStart, pStart + length - 1, iStart, i - 1);
            divide(pStart + length, pEnd - 1,i + 1, iEnd);
            break;
        }
    }*/
    int idx = inorderIdx[postorder[pEnd]];
    int length = idx - iStart;

    divide(pStart, pStart + length - 1, iStart, idx - 1);
    divide(pStart + length, pEnd - 1,idx + 1, iEnd);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    inorder.resize(n), postorder.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> inorder[i]; // 중위 순회
        inorderIdx[inorder[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i]; // 후위 순회
    }

    divide(0, n - 1, 0, n-1);
}