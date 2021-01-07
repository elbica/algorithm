#include<bits/stdc++.h>
using namespace std;

int arr[314159];

int main(){
    int n; long long k; cin>>n>>k;

    int temp=1, start=n-1;
    while(true){
        if(k>=start){
            k-=(start);
            arr[start]=temp;
            temp++; start--;
            if(k==0){
                for(int i=0; i<=start; i++) arr[i] = temp++;
                break;
            }
        }
        else{
             for(int i=0; i<=start; i++) arr[i] = temp++;
             for(int i=0; i<k;i++)
                swap(arr[i],arr[i+1]);
                break;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
}