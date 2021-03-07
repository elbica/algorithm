#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;
vector<map<string,int>> arr;

//조합 만들기 : 문자열 ori에 대해, num개 문자를 뽑아 조합 생성
void combi(string ori, int idx,string s, int num, int end){
    if(s.size()==num){
        if(arr[num].find(s)==arr[num].end()){
            arr[num].insert({s,1});
        }
        else arr[num][s]++;
        return;
    }
    //문자 끝에 도달
    if(idx==end) return;

    s.push_back(ori[idx]);
    combi(ori,idx+1,s,num,end);
    s.pop_back();
    combi(ori,idx+1,s,num,end);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    arr.resize(11);
    for(auto& o : orders){
        //먼저 손님이 주문한 음식들을 오름차순 정렬 한다
        sort(o.begin(),o.end());
        for(int i=2; i<=o.size(); i++){
            //각 음식들에 대해 모든 조합을 생성한다
            combi(o,0,"",i,o.size());
        }
    }
    for(auto c : course){
        if(arr[c].size()>1){
            vector<pair<string,int>> v(arr[c].begin(),arr[c].end());
            sort(v.begin(),v.end(),[](pair<string,int> a, pair<string,int> b){
                return a.second > b.second;
            });
            
            int check = v[0].second;
            if(check==1) continue; //한번만 주문했을 땐 패스
            for(auto a : v){
                if(a.second==check) answer.push_back(a.first);
                else break;
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}