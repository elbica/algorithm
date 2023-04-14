#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int answer;

bool visited[18][18][18];
vector<int> newGraph[18];
void run(int here, int wolf, int sheep, vector<int>& sheeps, vector<int>& wolfs, vector<int>& info, int parent){
    // cout<<"parent:"<<parent<<" here:"<<here<<" sheeps:"<<sheep<<" wolfs:"<<wolf<<endl;
    answer = max(answer, sheep);
    if(wolf == sheep) return;
    
    for(auto next: newGraph[here]){
        int nextWolf = wolf, nextSheep = sheep;
        if(info[next] == 1 && find(wolfs.begin(), wolfs.end(), next) == wolfs.end()){
            nextWolf++; 
            wolfs.push_back(next);
        }
        if(info[next] == 0 && find(sheeps.begin(), sheeps.end(), next) == sheeps.end()){
            nextSheep++; 
            sheeps.push_back(next);
        }
        
        if(visited[nextWolf][nextSheep][next]) continue;
        visited[nextWolf][nextSheep][next] = true;
        run(next, nextWolf, nextSheep, sheeps, wolfs, info, here);
        visited[nextWolf][nextSheep][next] = false;
        if(nextWolf != wolf) wolfs.pop_back();
        if(nextSheep != sheep) sheeps.pop_back();
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    /*
       1. visited[wolf][sheep][17]
       2. 
    */
    for(int i=0; i<edges.size(); i++) {
        // info[i] ==1 : 늑대
        auto e = edges[i];
        newGraph[e[0]].push_back(e[1]);
        newGraph[e[1]].push_back(e[0]);
    }
    visited[0][1][0] = true;
    vector<int> sheeps, wolfs;
    sheeps.push_back(0);
    run(0, 0, 1, sheeps, wolfs, info, -1);
    return answer;
}