#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int game[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int M,N;

int recur(int**& arr,int count)
{
   if(count>2) return 0;
    int ret=0;
   vector<vector<bool>> visited(N,vector<bool>(M,false));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){   
            if(visited[i][j]) continue;
            int C = 0;
            int** newarr = new int*[N];
                for(int z=0;z<N;z++) 
                    newarr[z] = new int[M];
                for(int k=0;k<N;k++)
                    for(int z=0;z<M;z++)
                        newarr[k][z] = arr[k][z];           

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j]=true;
 
            int check = newarr[i][j];
            newarr[i][j] = 0;

            if(check==0) continue;

            while (!q.empty()){   
                int hereX = q.front().second;
                int hereY = q.front().first;
                q.pop(); C++;
                visited[hereY][hereX]=true;

                for (int i = 0; i < 4; i++) {
                    int nextX = hereX + dx[i];
                    int nextY = hereY + dy[i];
                    if (nextX < 0 || nextY < 0 || nextX >= M || nextY >= N)  continue;
                    if (visited[nextY][nextX])  continue;
                    if (newarr[nextY][nextX] == check){
                        newarr[nextY][nextX]=0;
                        q.push({nextY, nextX});
                    }
                }
            }
            if(C) {
                for(int x=0; x<M;x++){
                    for(int y=N-1;y>=0;y--){
                        if(!newarr[y][x]) continue;
                        for(int pos = N-1; pos>=y; pos--)
                            if(!newarr[pos][x]){
                                swap(newarr[pos][x],newarr[y][x]);
                                break;
                            }
                    }
                }
                ret = max(ret,C*C+recur(newarr,count+1));
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>M>>N;

    int** game = new int*[N];
        for(int i=0;i<N;i++)
                game[i] = new int[M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>game[i][j];

    cout<<recur(game,0)<<endl;
}