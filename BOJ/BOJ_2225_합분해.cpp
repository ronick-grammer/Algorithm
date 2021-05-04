#include <iostream>
using namespace std;

//problem link: https://www.acmicpc.net/problem/2225

long dp[201][201];

int main(void){
    int n, k;

    cin >> n >> k;

    for(int i = 0; i <= n; i++){
        dp[1][i] = 1; // 1개의 숫자로 i 를 만들 수 있는 경우의 수는 1 이다
    }

    for(int i = 2; i <= k; i++){   // 두 개부터 숫자 [j] 를 만들 수 있는 경우의 수 구하기
        for(int j = 0; j <= n; j++){
            for(int m = 0; m <= j; m++){ 
                // 현재 [i] 개로 만들수 있는 숫자 [j]를 만들 수 있는 경우의 수는 
                // 앞서 구해진 [i-1]개로 만들 수 있는 숫자 [j] ~ [0] 까지의 경우의 수를 합해주면 된다.
                // 이렇게 해주면 숫자 [j]를 만들 수 있는 숫자들은 자신을 포함한 그 이하의 숫자들이다
                dp[i][j] += dp[i - 1][m];
            }
            dp[i][j] %= 1000000000;
        }
    }

    cout<<dp[k][n];
}
