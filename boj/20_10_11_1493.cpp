//https://burningjeong.tistory.com/327
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int length, width, height;
long long int N, result;
vector<int> input(21);//���� ����
int cube[21];//������ ���� ����

bool res = true;
void recur(int l, int w, int h, int i) {
	if (i == -1) {//��� ������ ť�긦 Ž������ ���
		//�� ������ �����ִ� ��� ����
		if (l > 0 && w > 0 && h > 0) 
			res = false;
		return;
	}
	if (input[i] > l || input[i] > w || input[i] > h || cube[i] == 0) {
		//���� ������ ť�긦 ���� �� ���ų�, �ش� ť�긦 �� ���� ��
		//ť�긦 �� �ܰ� ���̰� ���ȣ�� �Ѵ�
		recur(l, w, h, i - 1); return;
	}
	//�Ϲ����� ���
	//ť�긦 �ϳ� �ְ� 
	//������ ť�� ��, ������, �������� �����Ѵ�
	cube[i]--; result++;

	//����
	recur(l, w - input[i], input[i], i);
	//������
	recur(l - input[i], input[i], input[i], i);
	//����
	recur(l, w, h - input[i], i);
}
int main() {
	cin >> length >> width >> height;
	cin >> N;

	for (int i = 0; i < N; i++) { 
		int x, y; cin >> x >> y;
		cube[x] = y; //������ ���� �Է�
	}
	for (int i = 1, j = 0; j < 20; i *= 2, j++)
		input[j] = i; //������ ť�� ���� ����

	recur(length, width, height, 19);
	if (res) cout << result << endl;
	else cout << -1 << endl;
}