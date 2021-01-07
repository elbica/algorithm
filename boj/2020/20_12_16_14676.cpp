#include<iostream>
#include<vector>
using namespace std;

int N, M, K;
vector<vector<int>> adj;
vector<int> check;
vector<int> degree;
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M>>K;

    adj.resize(N+1);
    check.resize(N+1);
    degree.resize(N+1);

    for(int i=0;i<M;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        degree[y]++;
    }
    bool flag=true;
    //차수를 이용해 건설 조건 충족 여부를 상수시간에 알아 낸다
    for(int i=0;i<K;i++){
        int version, x; cin >> version >> x;
        if(version==1){//건설
            if(degree[x]>0){flag=false; break;}
            check[x]++;

        //처음 건설된 경우 그 자식들(최대 3개)의 차수를 감소시킨다
            if(check[x]==1)
                for(int c : adj[x])
                    degree[c]--;
        }
        else{
            if(check[x]==0) {
                flag=false; break;
            }
            else check[x]--;
        //건물이 아예 없어진 경우 자식들 차수를 증가시킨다
            if(check[x]==0){
                for(int c : adj[x])
                    degree[c]++;
            }
        }
    }
    if(flag) cout<<"King-God-Emperor"<<endl;
    else cout<<"Lier!"<<endl;
    
}