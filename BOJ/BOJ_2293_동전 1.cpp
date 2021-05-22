//problem link: https://www.acmicpc.net/problem/2293
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int arr[101];

int main(void){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }

    dp[0] = 1; 
    for(int i = 1; i <= n; i++){
        for(int j = arr[i]; j <= k; j++){
            // j원 을 만들수 있는 경우의 수는
            // 현재까지 j원을 만들수 있는 경우의 수 + 현재까지 만들어진 j - arr[i]원을 만들수 있는 경우의 수이다.
            // j - arr[i] 의 의미는 (j - arr[i]) + arr[i] 로서,
            // (j - arr[i]) 와 arr[i] 로 j 원을 만들 수 경우의 수를 말한다.
            dp[j] += dp[j - arr[i]];
        }
    }

    cout<<dp[k]<<'\n';
}
