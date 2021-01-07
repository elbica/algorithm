#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2147483647000
using namespace std;

vector<vector<pair<long long,long long>>> adj;
 vector<long long> result;
int N,M,K;

void func(){
    //다익스트라는 visited배열을 쓰지 않는다
    priority_queue<pair<long long,long long>> pq;

    //거리를 기록하는 배열을 쓴다
    result[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
        long long here = pq.top().second;
        long long cost =-pq.top().first;
        pq.pop();

        //주의 : 계산해 놓은 거리보다 cost가 더 크면 무시하도록 하자
        if(result[here]<cost) continue;
        for(auto& i : adj[here]){
            long long next = i.first;
            long long dist = i.second;

                if(result[next]> result[here]+dist){
                    //자식 : 부모 + 간선 가중치
                    result[next]=dist + result[here];
                    pq.push({-result[next],next});
                }
            
        }
    }
}
int main(){
    cin>>N>>M>>K;
    adj.resize(N+1);
    result.assign(N+1,INF);

    for(int i=0;i<M;i++){
        int u,v,c; 
        scanf("%d %d %d",&u,&v,&c);
        adj[v].push_back({u,c}); //정점, 가중치
    }

    //임시로 놓은 시작 정점과 
    //면접장끼리 가중치 0인 간선을 추가하면
    //한 번의 탐색으로 계산할 수 있다
    for(int i=0;i<K;i++) {
        int x; scanf("%d",&x);
        adj[0].push_back({x,0});
        adj[x].push_back({0,0});
        }

    func();
    //가장 먼 정점과 그 거리
    long long check=0, node=0;
    for(int i=1; i<result.size();i++)
        if(result[i]>check) {
            check=result[i];
            node=i;
        }
    cout<<node<<'\n'<<check<<'\n';
    
}