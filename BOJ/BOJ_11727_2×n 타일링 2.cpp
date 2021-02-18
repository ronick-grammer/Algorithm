#include <iostream>
using namespace std;

// problem link : https://www.acmicpc.net/problem/11727

int dp[1001];

int main(void){
    int n;
    cin>>n;

    dp[1] = 1; // 2x1 일때 는 한가지 방법뿐
    dp[2] = 3; // 2x2 일때는 세가지 방법
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] * 2; // 점화식 d(n-1) + d(n-2) * 2
        dp[i] %=  10007;
    }

    cout<<dp[n]<<endl;
}
