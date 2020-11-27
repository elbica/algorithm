//https://burningjeong.tistory.com/327
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int length, width, height;
long long int N, result;
vector<int> input(21);//길이 저장
int cube[21];//종류별 개수 저장

bool res = true;
void recur(int l, int w, int h, int i) {
	if (i == -1) {//모든 종류의 큐브를 탐색했을 경우
		//빈 공간이 남아있는 경우 실패
		if (l > 0 && w > 0 && h > 0) 
			res = false;
		return;
	}
	if (input[i] > l || input[i] > w || input[i] > h || cube[i] == 0) {
		//남은 공간에 큐브를 넣을 수 없거나, 해당 큐브를 다 썼을 때
		//큐브를 한 단계 줄이고 재귀호출 한다
		recur(l, w, h, i - 1); return;
	}
	//일반적인 경우
	//큐브를 하나 넣고 
	//공간을 큐브 위, 오른쪽, 뒤쪽으로 분할한다
	cube[i]--; result++;

	//뒤쪽
	recur(l, w - input[i], input[i], i);
	//오른쪽
	recur(l - input[i], input[i], input[i], i);
	//위쪽
	recur(l, w, h - input[i], i);
}
int main() {
	cin >> length >> width >> height;
	cin >> N;

	for (int i = 0; i < N; i++) { 
		int x, y; cin >> x >> y;
		cube[x] = y; //종류별 개수 입력
	}
	for (int i = 1, j = 0; j < 20; i *= 2, j++)
		input[j] = i; //종류별 큐브 길이 설정

	recur(length, width, height, 19);
	if (res) cout << result << endl;
	else cout << -1 << endl;
}