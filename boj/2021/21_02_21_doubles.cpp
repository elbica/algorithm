#include<bits/stdc++.h>
using namespace std;

int main(){

    while(true){
        vector<int> inputs;
        int x;
        while(cin>>x){
            if(x==-1) return 0;
            if(x==0) break;
            inputs.push_back(x);
        }
        int count = 0;
        for(int i=0; i<inputs.size()-1; i++){
            int check = inputs[i];
            
            for(int j = 0; j<inputs.size(); j++)
                if(inputs[j] == 2*check) count++;
        }
        cout<<count<<'\n';
    }
}