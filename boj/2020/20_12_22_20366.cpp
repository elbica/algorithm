#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[600];
int N;
int main(){
    cout.tie(0); cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr,arr+N);
    ll answer = 3987654321;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            ll sum = arr[i]+arr[j];
            int low = 0, high = N-1;
            if(low==i||high==i||low==j || high==j) continue;
            while(low<high){
                //중복 안되게 예외 처리
                if(high==j||high==i){high--; continue;}
                if(low==i||low==j){low++; continue;}

                //답 갱신
                if(answer > abs(sum-(arr[low]+arr[high])))
                    answer = abs(sum-(arr[low]+arr[high]));

                //투 포인터
                if(arr[low]+arr[high]>sum) high--;
                else if(arr[low]+arr[high]<sum) low++;
                else{ 
                    cout<<0<<endl; return 0;
                }
            }
        }
    }
    cout<<answer<<endl;
}