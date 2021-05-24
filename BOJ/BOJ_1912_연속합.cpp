//problem link: https://www.acmicpc.net/problem/1912
#include <iostream>
#include <algorithm>
using namespace std;

int nums[100001];
int dp[100001];

int main(void){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &nums[i]);
    }

    int result = nums[1];
    dp[1] = nums[1];
    for(int i = 2; i <= n; i++){
        // "단, 수는 한 개 이상 선택해야 한다." 의 지문에 의하면 자기 자신도 비교하여야 한다.
        // dp[i] = max(자기 자신, 연속해서 계속 더해온 수 + 자기 자신, 바로 직전 수 + 자기 자신)
        dp[i] = max(nums[i], max(dp[i-1] + nums[i], nums[i-1] + nums[i]));
        result = max(result, dp[i]);
    }

    cout<<result<<'\n';
}
