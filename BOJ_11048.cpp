#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(void){
    int n, m;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> dp[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            // DP(r,c) = max(DP(r-1,c), DP(r, c-1)) + DP(r,c) 
            // DP(r-1,c-1) 을 포함시키지 않는 이유는 위의 점화식으로도 충분히 조건을 만족하기 때문이다.
            if(i != 0 && j != 0){ 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dp[i][j];
            }

            else if(i == 0 && j > 0){  // ('현재 행' - 1) >= 0 을 항상 만족해야 한다.   
                dp[i][j] = dp[i][j] + dp[i][j-1];
            }

            else if(j == 0 && i > 0){ // ('현재 열' - 1) >= 0 을 항상 만족해야 한다.  
                dp[i][j] = dp[i][j] + dp[i-1][j];
            }
        }
    }

    cout<<dp[n-1][m-1]<<endl;
}
