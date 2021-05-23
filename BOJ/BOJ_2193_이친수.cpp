//problem link: https://www.acmicpc.net/problem/2193
#include <iostream>
using namespace std;

// int의 범위는 초과하므로 lon으로 선언
long dp[91];

int main(void){
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        // 점화식 dp(i) = dp(i-1) + dp(i-2), 이번껀 쉬웠다.
        dp[i] = dp[i-1] + dp[i-2]; 
    }

    cout<<dp[n]<<'\n';
}
