//
// Created by Kim So Hee on 2022/06/28.
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
int chess[50][50];

/*
 *
 * @description
 *   브루트 포스 : 2가지의 체스판과 8x8로 자른 판 비교
 *   2가지의 체스판을 flag 변수로 구분한다
 *   한 행마다 시작하는 컬러가 바뀌므로, flag를 토글해준다
 *   flag와 chess(입력)이 일치하지 않으면 바꿔야 한다!
 *
 * */

int checkChess(int i, int j, int flag) {
    int answer = 0;
    for (int k = i; k < i + 8; ++k) {
        for (int l = j; l < j + 8; ++l) {
            if (l % 2 == 0 && chess[k][l] != flag) answer++;
            else if (l % 2 == 1 && chess[k][l] == flag) answer++;
        }
        flag = !flag;
    }
    return answer;
}

int main() {
    cin >> N >> M;
    int answer = 987654321;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            if(c=='B') chess[i][j] = 1;
            else chess[i][j] = 0;
        }
    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; ++j) {
            answer = min(checkChess(i, j, 0), answer);
            answer = min(checkChess(i, j, 1), answer);
        }
    }
    cout << answer;
}
