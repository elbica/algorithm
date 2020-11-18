#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, D, answer;
int input[13][3];

int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) 
		// ���� ��ġ, ���� ��ġ, ����
		cin >> input[i][0] >> input[i][1] >> input[i][2];
	
	input[N][0] = input[N][1] = D;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,0 }); // {���, ���� ��ġ}

	while (!pq.empty()) {
		int here = pq.top().second; //Ž���� ���� ��ġ
		int dist = -pq.top().first; //�ɸ��� �ּ� �Ÿ�
		pq.pop();

		//���� ����
		if (here == D) { answer = dist; break; }

		//Ž���� ���� ��ġ����, ���� ��ġ�� �� ū �������� ť�� �ִ´�
		for(int i = 0 ; i <= N; i++)
			if (input[i][0] >= here) {
				int there = input[i][1]; //���ο� ���� ��ġ
				int nextdist = dist + 
					(input[i][0] - here) + input[i][2]; //���ο� �ּ� �Ÿ�
				pq.push({ -nextdist,there });
			}
	}
	cout << answer << endl;
}