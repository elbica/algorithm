#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> adj;

//한 글자만 다를 때 간선 연결 가능
bool check(string a, string b){
    int Count = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) Count++;
    }
    return Count==1;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int endidx = -1;
    for(int i=0; i<words.size();i++){
        if(words[i]==target) endidx = i;
    }
    if(endidx==-1) return 0;

    adj.resize(words.size()+1);
    words.push_back(begin);
    int start = words.size()-1;
    //간선 연결
    for(int i=0; i<words.size(); i++){
        for(int j=i+1; j<words.size(); j++){
            if(check(words[i],words[j])){
                adj[i].push_back(j); 
                adj[j].push_back(i);
            }
        }
    }

    //다익스트라
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    vector<int> dist(start+1,99999);
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = pq.top().first; pq.pop();
        if(cost > dist[here]) continue;
        for(int i : adj[here]){
            int newCost = cost+1;
            if(dist[i]>newCost){
                dist[i] = newCost;
                pq.push({newCost, i});
            }
        }
    }
    if(dist[endidx]==99999) answer = 0;
    else answer = dist[endidx];
    return answer;
}