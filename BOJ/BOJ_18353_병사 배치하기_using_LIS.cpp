#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

//problem link: https://www.acmicpc.net/problem/18353

int soldiers[2001];
int dp[2001];

int main(void){
    int n;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        soldiers[i] = x;
    }

    fill(dp + 1, dp + 1 + n, 1); // 1로 채움
    // dp[i] = max(dp[i], dp[j] + 1), if (soldiers[i] < soldiers[j])
    // 시간 복잡도가 N^2 로 범위가 2000 까지라 LIS(Loingest Increasing Subsequences) 알고리즘으로 수행할수 있다
    for(int i = 2; i <= n; i++){ // 전 값을 비교하므로 2 부터 시작
        for(int j = 1; j < i; j++){
            if(soldiers[i] < soldiers[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    sort(dp + 1, dp + 1 + n); // 오름차순 정렬로 dp[n] 값이 남아있는 최대 병사 수를 가지게 한다
    cout<<n - dp[n]<<'\n'; // 열외된 병사 수 출력
}
