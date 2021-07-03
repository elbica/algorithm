#include<bits/stdc++.h>
using namespace std;

//45�� �ݽð� ȸ�� : (idx % 8) + 1 : 1 ~ 8 ������ ��
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
pair<int,int> adj[4][4]; //{��ȣ, ����}
pair<int,int> fish[17]; //����� ��ǥ ����

int func(int y, int x){
    //���� : ������ ��� �� ���� �� ��
    if(y < 0 || y >= 4 || x < 0 || x >= 4) return 0;
    
    int answer = 0;
    pair<int,int> a[4][4], f[17];
    memcpy(f,fish,sizeof(fish));
    memcpy(a,adj,sizeof(adj));

    //1. ���� (y,x)�� ����⸦ �Դ´�. 
    int ret = adj[y][x].first; //���� ����� ��ȣ
    int direction = adj[y][x].second; //��� ����

    fish[ret] = {-1,-1}; //���� ������� ��ǥ�� (-1,-1)�� ����.
    adj[y][x].second = -2; //�� �ִ� �ڸ��� ������ -2�� ����.

    //2. ����Ⱑ ��ȣ ����� �̵��Ѵ�
    for(int i=1; i<=16; i++){
        //���� Ž�� ������ ����̰ų�, ���� ���
        if(fish[i].first == -1) continue;
        bool flag = false;
        int count = 0, herey = fish[i].first, herex = fish[i].second;
        int& fDirect = adj[herey][herex].second;

        while(!flag){
            //�̵��� �� ���� ������ �ٲ۴�.
            if(count == 8) break; //��� ���� �̵� �Ұ�
            if(flag) break; //�̵� ���� ��

            //�̵��� ���� ��ǥ, ����� ��ȣ, ����� ����
            int newy = herey + dy[fDirect], newx = herex + dx[fDirect];
            int newnum = adj[newy][newx].first, newdirec = adj[newy][newx].second;
            
            //�̵��� ������ ��踦 ����ų� ����� ��� (������ -2 ������ �˻�)
            if(newy >=4 || newy < 0 || newx >=4 || newx < 0 ||
                adj[newy][newx].second == -2) {
                    fDirect = (fDirect % 8) + 1; count++;
                    continue;
                }
            //�������� ��� swap.
            fish[i] = {newy, newx}; fish[newnum] = {herey,herex};
            adj[newy][newx].swap(adj[herey][herex]);
            flag = true;
        }
    }
    //3. �� �̵��Ѵ�
    //���� �ڸ��� ���� ó�� (���⿡ -1)�� �Ѵ�
    adj[y][x].second = -1;

    //�ִ� 3������ ��� �߻�. �� �� ���� ���� ���� ����
    for(int i=1; i<=3; i++){
        int sharky = y + i * dy[direction], sharkx = x + i * dx[direction];

        //�̹� ���� ���� �ǳ� �ڴ�
        if(adj[sharky][sharkx].second == -1) continue;
        answer = max(answer, func(sharky, sharkx) + ret);
    }
    //4. �ʰ� ����� ���¸� ������� ���� ���´�
    memcpy(adj,a,sizeof(a));
    memcpy(fish,f,sizeof(f));
    return answer;
}

int main(){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++) {
            cin>>adj[i][j].first>>adj[i][j].second;
            fish[adj[i][j].first] = {i,j};
            }
   cout<< func(0,0);
}