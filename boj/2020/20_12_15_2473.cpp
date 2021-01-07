#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2121987654321
using namespace std;
vector<int> input;
int n;

int main(){
    cin>>n;
    input.resize(n);
    int result[3]={};
    long long answer=INF;

    for(int i=0;i<n;i++) cin>>input[i];
    sort(input.begin(),input.end());

    //투 포인터를 이용한 이진탐색.. 약간 생소하다
    for(int i=0;i<n-1;i++){
        int point1 = i + 1, point2 = n - 1;
        long long check = -input[i];

        while(point1 < point2){
            long long sum = input[point1] + input[point2];
            if (abs(-check + sum) < answer)
            {//답이 갱신이 된다면 저장한다
                answer = abs(-check + sum);
                result[0] = input[point1];
                result[1] = input[point2];
                result[2] = input[i];
            }
            //check 값과 근접한 sum을 찾아나간다
            //투 포인터 활용 -> 총 시간복잡도 O(n^2)
            if(sum<check) point1++;
            else if(sum>check) point2--;
            else {
                i=n; break;
            }
        }

    }
    sort(result, result + 3);
    for (int i = 0; i < 3; i++)
        cout << result[i] << ' ';
}