#include <iostream>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1463

int dp[1000000];

int main(void){
    int n;
    cin>>n;
    
    //점화식
    //dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1, dp[i / 3] + 1)
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + 1; // 1을 하나 빼주므로 연산횟수 하나 증가

        if(i % 2 == 0){ // 2로 나뉘어 질 경우
            dp[i] = min(dp[i], dp[i/2] + 1); // 1을 하나 뺀 경우의 최소 연산 횟수와 2로 나누었을 경우의 최소 연산 횟수를 비교 
        }

        if(i % 3 == 0){ // 3으로 나뉘어 질 경우
            // 1을 하나 뺀 경우의 최소 연산 횟수와 2로 나누었을 경우의 최소 연산 횟수 or 3으로 나누었을 경우의 최소 연산 횟수를 비교
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    cout<<dp[n]<<'\n';
}
