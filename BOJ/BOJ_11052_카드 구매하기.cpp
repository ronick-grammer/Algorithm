#include <iostream>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/11052

int arr[1001];
int dp[1001];

int main(void){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }

    for(int i = 1; i <= n; i++){
        // 카드 i 개로 만들 수 있는 최대 금액은 (i-j 개로 만들 수 있는 최대 금액 + 현재 카드 j개가 포함된 카드팩의 금액) 이다.
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }

    cout<<dp[n]<<'\n';
}
