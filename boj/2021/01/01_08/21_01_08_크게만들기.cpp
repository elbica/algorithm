#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<int> input;

int main(){
    //앞에 자기보다 작은 수가 있으면 그 수를 삭제시킨다.
    //삭제시킬 수 있는 횟수는 k번이고, 스택을 활용한다
    cin>>n>>k;
    input.resize(n);
    string s; cin>>s;
    stack<char> st; st.push(s[0]);
    for(int i=1;i<s.size();i++){
        while(k && !st.empty() && st.top() < s[i]){
            st.pop(); k--;
        }
        st.push(s[i]);
    }
    while(k-->0) st.pop();
    string result=""; 
    while(!st.empty()){
        result.push_back(st.top()); st.pop();
        //주의 : result = st.top() + result; 은 시간초과가 난다.
        // + 연산에서 O(n)복잡도가 걸리는 것 같다
    }
    for(int i = result.size()-1; i>=0; i--) cout<<result[i];
    
}