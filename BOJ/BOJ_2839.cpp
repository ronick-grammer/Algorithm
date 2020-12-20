#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 5001 // 최대치 킬로 그램

int arr[2] = {3, 5}; // 3kg 봉지, 5kg 봉지

int main(void){
    int n;
    cin>>n;

    vector<int> dp(n+1, MAX); // 모든 인덱스를 최대치 kg으로 초기화

    // dp[0]: [0]kg 그램 설탕은 0 봉지가 필요
    // [3]kg - 3kg 봉지 = 0 + 1봉지, [5]kg - 5kg 봉지 = 0 + 1 봉지 로 시작하기 위하여 
    dp[0] = 0; 
    for(int i = 0; i < 2; i++){ // 3kg 과 5kg, 두 봉지
        int num = arr[i];
        for(int j = num; j <= n; j++){ 
            dp[j] = min(dp[j], dp[j-num] + 1); // 이미 기록되어 있는 경우를 대비해, 최소 봉지의 갯수를 기록한다.
        }
    }
    
    if(dp[n] == MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<dp[n]<<endl;
    }
}
