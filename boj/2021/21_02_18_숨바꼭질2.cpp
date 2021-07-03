#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[100001],result[100001];
int main(){
    cin>>n>>k;
    memset(arr,-1,sizeof(arr));
    queue<int> q;
    q.push(n);
    
    int count = 0;
    while(!q.empty()){
        int qsize = q.size();
        //cout<<"level"<<count<<endl;
        for(int i=0; i<qsize; i++){
            int here = q.front(); q.pop();
            
            if(here<0 || here>100000) continue;
            if(arr[here]!=-1&& count > arr[here]) continue;
            else {//cout<<here<<endl;
                arr[here] = count;
                result[here]++;
                q.push(here+1);
                q.push(here-1);
                if(here < k)
                q.push(2*here);
            }
        }
        count++;
    
    }
    cout<<arr[k]<<'\n'<<result[k];

}