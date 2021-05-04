#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];
int stairs[301];

int main(void){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        stairs[i] = x;
    }
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    
    for(int i = 3; i <= n; i++){
        // 현재 계단은 연속 3번 밝은 계단이 아니라고 가정해야 한다.
        // 현재 계단 i와 i-1, i-3, 현재 계단 i와 i-2, i-3 를 밣은 두가지 경우를 고려한다.
        // 그럴 경우의 점화식은 현재계단[i] = max([i-2] 까지 밟은 계단의 점수 + [i] 계단 점수, [i-3] 까지 밝은 계단의 점수 + [i+1]계단 점수, [i]계단 점수)
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }
    
    cout<<dp[n]<<'\n';
}
