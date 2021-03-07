#include<bits/stdc++.h>
using namespace std;

int n,m,d,answer;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool input[2][15][15];

int func(int row, int idx[3]){
//인덱스 범위 : y < row, x < m
//i1, i2, i3 각각 bfs실행. visited배열은 따로, 처음 만나는 적 좌표 set에 저장
//set에 담긴 좌표들 input[1]을 0으로 만든다
//return set.size() + func (row-1, ...)
//기저 : row == -1 일때 0 리턴
    if(row == -1) return 0;
    set<pair<int,int>> s;

    for(int i=0; i<3; i++){
        queue<pair<int,int>> q;
        vector<pair<int,int>> v;
        //맨 밑 성의 n+1 행 포함
        bool visited[16][15] = {0,} , flag = false;
        q.push({row,idx[i]});
        int level = 0;

        while(!q.empty()){
            //level별 순회
            int qsize = q.size();
            //쏠 수 있는 거리를 넘어가면 break
            if(level++ == d ) break;
            for(int j = 0; j < qsize; j++){
                int herey = q.front().first;
                int herex = q.front().second; q.pop();
                if(visited[herey][herex]) continue;
                visited[herey][herex] = true;
            
                for(int k=0; k<4; k++){
                    int newy = herey + dy[k];
                    int newx = herex + dx[k];
                    if(newy < row && newy >=0 && newx >=0 && newx < m){
                        if(input[1][newy][newx]) {
                            //level이 같은 적들 중, 가장 왼쪽인 적을 뽑기 위해
                            //x 좌표가 앞에 오게 저장한다
                            v.push_back({newx,newy});
                            flag = true;
                            }
                        q.push({newy,newx});
                    }
                }
            }
            if(flag) break;
        }
        if(v.size() != 0){
            sort(v.begin(), v.end()); 
            s.insert(v[0]); //set엔 적들의 {x, y} 저장되어 있음
        }
    }
    for(auto p = s.begin(); p != s.end(); p++){
        int y = (*p).second, x = (*p).first; 
        input[1][y][x] = 0;
    }
    return s.size() + func(row - 1, idx);
}

int main(){
    cin>>n>>m>>d;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin>>input[0][i][j];
        
    for(int i=0; i<m-2; i++)
        for(int j=i+1; j<m-1; j++)
            for(int k=j+1; k<m; k++){
                 memcpy(input[1],input[0],sizeof(input[0]));
                 int para[3] = {i,j,k};
                 answer = max(answer, func(n, para));
            }
   cout<<answer; 
}