#include<bits/stdc++.h>
#define vvb vector<vector<bool>>
using namespace std;

vector<vvb> nemo;
int arr[500][500];
long long answer;

int N,M;
void rotate(){ //4방향 회전
    for(int z = 0; z < 4; z++){
        //중간에 벡터 크기가 변하기 때문에 미리 사이즈를 받아 놓는다
        int s = nemo.size();
        for(int ne = 0; ne < s; ne++){
            int n = nemo[ne].size(), m = nemo[ne][0].size();
            vvb newNemo(m,vector<bool>(n));

            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    newNemo[j][n-1-i]= nemo[ne][i][j];

            nemo.push_back(newNemo);
        }
    }
}
void symmetry(){ //대칭
    int s = nemo.size();
    for(int k = 0; k < s; k++){
        int n = nemo[k].size(), m = nemo[k][0].size();
        vvb newNemo(n,vector<bool>(m));

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                newNemo[i][m-1-j] = nemo[k][i][j];
            
        nemo.push_back(newNemo);
    }
}
void cal(int y, int x, vvb ne){ //탐색 시작 점 (y, x)
    long long temp = 0;

    for(int i = 0; i<ne.size(); i++)
        for(int j=0; j<ne[0].size(); j++)
            if(ne[i][j]) temp += arr[y+i][x+j];
            
    answer = max(answer, temp);
}
int main(){
    //전처리 : 모든 가능한 회전, 대칭의 모양을 저장
    nemo.push_back( vvb(1,vector<bool>(4,1)));
    nemo.push_back( vvb(2,vector<bool>(2,1)));

    vvb temp = vvb(3,vector<bool>(2,1));
    temp[0][1] = temp[1][1] = 0;
    nemo.push_back(temp);

    temp[1][1] = 1; temp[2][0] = 0;
    nemo.push_back(temp);

    temp[2][0] = 1; temp[2][1] = 0;
    nemo.push_back(temp);

    rotate(); symmetry();
    //벡터 중복 원소 제거 : sort 후 unique, erase 사용
    sort(nemo.begin(),nemo.end());
    nemo.erase(unique(nemo.begin(),nemo.end()),nemo.end());
  
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) cin>>arr[i][j];

    for(auto ne : nemo){
        int n = ne.size(), m = ne[0].size();
        for(int i=0; i<N; i++){
            if(n + i > N) break;
            for(int j=0; j<M; j++){
                if(j + m > M) break;
                cal(i,j,ne);
            }
        }
    }
    cout<<answer<<endl;
}