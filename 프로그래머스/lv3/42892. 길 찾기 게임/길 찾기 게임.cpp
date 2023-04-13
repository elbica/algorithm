#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
vector<vector<int>> graph;
vector<int> postorderV, prevorderV; 
int idMap[100001];
int graphRoot;

void run(int start, int end, int prev, vector<vector<int>>& nodeinfo){
    int maxY = -1, root = -1, idx = -1;
    for(int i=start; i<=end; i++){
        if(maxY < nodeinfo[i][1]){
            maxY = nodeinfo[i][1];
            idx = i;
            root = idMap[nodeinfo[i][0]];
        }
    }
    // cout<<prev<<' '<<root<<endl;
    if(prev!= -1) graph[prev].push_back(root);
    if(prev == -1) graphRoot = root;
    
    if(start <= idx - 1) run(start, idx-1, root, nodeinfo);
    if(idx+1 <= end) run(idx+1, end, root, nodeinfo);
}

void order(int cur, int o){
    if(o == 0) prevorderV.push_back(cur);
    for(auto next : graph[cur]) order(next, o);
    if(o != 0) postorderV.push_back(cur);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int id = 1;
    for(auto n : nodeinfo) idMap[n[0]] = id++;
    graph.resize(id);
    
    sort(nodeinfo.begin(), nodeinfo.end());
    // for(auto n : nodeinfo) cout<<'('<<n[0]<<", "<<n[1]<<") ";
    /*
       1. int start, int end, root : start ~ end 사이에 있는 가장 큰 y 좌표, prev: 이전 root
       2. graph[prev].push_back(root) !! prev, root 노드 id로 변환 !!
       3. start ~ root -1, root+1 ~ end로 재귀 호출 (값 범위 체크하기)
    */
    
    run(0, nodeinfo.size() - 1, -1, nodeinfo);
    order(graphRoot, 0);
    order(graphRoot, 1);
    vector<vector<int>> answer;
    answer.push_back(prevorderV);
    answer.push_back(postorderV);
    return answer;
}