//problem link: https://www.acmicpc.net/problem/1890
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
int board[100][100];
// "경로의 개수는 2^63-1보다 작거나 같다." 의 지문 때문에 범위를 최대한으로 잡아준다.
long long dp[100][100];

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %d", &board[i][j]);
        }
    }

    dp[0][0] = 1; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 마지막 도착점은 0 이므로 계산을 해주면 안된다.
            if(i == n - 1 && j == n - 1)
                continue;
            
            // 점프해서 도착 했을때, 그 지점으로 갈 수 있는 경우의 수를 더해준다.
            // 물론 범위 체크를 해준다.
            if(j + board[i][j] < n)
                dp[i][j + board[i][j]] += dp[i][j];
            
            if(i + board[i][j] < n)
                dp[i + board[i][j]][j] += dp[i][j];
        }
    }
    
    cout<<dp[n-1][n-1]<<'\n';
}
