#include <bits/stdc++.h>
using namespace std;

bool che[100];
char adj[100];

bool check(const string tree){
    int i = 0;
    memset(che,false,sizeof(che)); che[0]=true;
    //바로 전 스킬이 true가 됐는지 확인
    while(tree[i]!=NULL){
        if(!che[adj[tree[i]]]) return false;
        che[tree[i]]=true;
        i++;
    }
    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    char temp = 0;

    //간선 거꾸로 저장
    for(char c : skill){
        adj[c] = temp;
        temp = c;
    }
    for(int i=0;i<skill_trees.size(); i++){
        if(check(skill_trees[i])) answer++;
    }
    return answer;
}