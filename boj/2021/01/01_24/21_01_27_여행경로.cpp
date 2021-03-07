#include <string>
#include <vector>
using namespace std;
#include<unordered_map>
#include<iostream>
#include<set>

unordered_map<string,int> um;
string number[10001];
int adj[10001][10001], checkNum;
vector<string> answer;

//백트래킹
void dfs( int here, vector<string> v){
    if(v.size()==checkNum){answer = v; return;}
    
    for(int i=1; i<=um.size(); i++){
        if(adj[here][i]){
            adj[here][i]--, v.push_back(number[i]);
            dfs(i,v);
            adj[here][i]++, v.pop_back();
            }
        }   
    }
vector<string> solution(vector<vector<string>> tickets) {
    int num=1; checkNum = tickets.size()+1; int start = 0;
    //set 오름차순 저장
    set<string,greater<string>> s;

    //string마다 번호 부여
    for(auto& t : tickets) s.insert(t[0]), s.insert(t[1]);
    for(auto i = s.begin(); i!=s.end(); i++){
        //시작점 번호 저장
        if(*i=="ICN") start = num;
        //string->int, int->string
        um[*i]=num, number[num++] = *i;
    }
    for(auto t : tickets){
        string s1 = t[0], s2 = t[1];
        //간선 연결
        adj[um[s1]][um[s2]]++;
    }
    dfs(start,vector<string>(1,"ICN"));
    return answer;
}