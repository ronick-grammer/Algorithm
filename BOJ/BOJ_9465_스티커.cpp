#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/9465

int t;
vector<int> result;

int main(void){
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        
        vector<vector<int> > s(4, vector<int>(n + 1, 0));
        
        for(int j = 1; j <= 2; j++){
            for(int k = 1; k <= n; k++){
                scanf(" %d", &s[j][k]); // 시간을 줄이기 위해 scanf
            }
        }
        vector<vector<int> > dp(3, vector<int> (n + 1, 0));
        
        dp[1][1] = s[1][1];
        dp[2][1] = s[2][1];
        
        for(int j = 2; j <= n; j++){ 
            // 1행 점화식: dp[1][n] = max(dp[2][n-1], dp[2][n-2]) + sticker[1][n]
            // 2행 점화식: dp[2][n] = max(dp[1][n-1], dp[1][n-2]) + sticker[2][n]
            dp[1][j] = max(dp[2][j-1], dp[2][j-2]) + s[1][j];
            dp[2][j] = max(dp[1][j-1], dp[1][j-2]) + s[2][j];
        }

        result.push_back(max(dp[1][n], dp[2][n]));
    }
    
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<'\n';
    }
}
