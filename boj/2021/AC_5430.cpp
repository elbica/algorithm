#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        //명령 입력
        string cmd; cin>>cmd;

        //배열 입력
        int n; cin>>n;
        string p; cin>>p;
        if(n==0){
            bool flag = true;
            for(auto c : cmd)
                if(c=='D') flag = false;
            if(flag) cout<<"[]"<<'\n';
            else cout<<"error"<<'\n';
            continue;
        }
        p = p.substr(1,p.size()-2);
        istringstream ss(p);
        string bf;
        
        vector<string> input;
        while(getline(ss,bf,',')){
            input.push_back(bf);
        }

        //수행
        bool front = 1, errFlag = false;
        int frontIdx = 0;
        int backIdx = n-1;
        for(auto c : cmd){
            if(c=='R'){
                front = (front+1)%2;
            }else{
                if(n==0){
                    cout<<"error"<<'\n';
                    errFlag=true; 
                    break;
                }
                if(front){
                    frontIdx++;
                    n--;
                }else{
                    backIdx--;
                    n--;
                }
            }
        }
        if(errFlag) continue;
        string result="[";
        vector<string> output;
        output.push_back("[");

        if(front){
        for(int i=frontIdx; i<=backIdx; i++){
            // result+=(input[i]+",");
            output.push_back(input[i]);
            output.push_back(",");
            }
        }
            
        else{
        for(int i=backIdx; i>=frontIdx; i--){
            // result+=(input[i]+",");
            output.push_back(input[i]);
            output.push_back(",");
            }
        }
        // result.pop_back();
        // result+="]";
        if(output.size()>1) output.pop_back();
        output.push_back("]");
        // cout<<result<<'\n';
        for(auto s : output) cout<<s;
        cout<<'\n';
    }
}