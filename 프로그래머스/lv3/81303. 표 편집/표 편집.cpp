#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<pair<int,pair<int,int>>> st;
    vector<int> next(n + 2), prev(n + 2); 
    int here = k + 1;
    
    // start: 0, end : n+1
    for(int i=0; i<=n+1; i++) next[i] = i+1, prev[i] = i-1;
    
    
    for(auto c : cmd){
        if(c[0]=='U'){
            int num = stoi(c.substr(2));
            while(num--) here = prev[here];
            
        }
        if(c[0]=='D'){
            int num = stoi(c.substr(2));
            while(num--) here = next[here];
        }
        if(c[0]=='C'){
            int pr = prev[here], ne = next[here];
            st.push({here, {pr, ne}});
            next[pr] = ne;
            prev[ne] = pr;
            if(ne == n+1) here = pr;
            else here = ne;
            
        }
        if(c[0]=='Z'){
            auto [z, cord] = st.top(); st.pop();
            next[cord.first] = prev[cord.second] = z;
        }
   
        
    }
    string answer = "";
    int s = 0, p = 0;
    vector<bool> check(n+2);
    while((s = next[s] )!= n+1) check[s] = true;
    for(int i=1; i<=n; i++) if(check[i]) answer.push_back('O'); else answer.push_back('X');
    return answer;
}