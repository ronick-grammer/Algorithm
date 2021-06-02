//problem link: https://www.acmicpc.net/problem/1520
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int map[502][502];
int dp[502][502];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int row, int column){
    if(row <= 0 || row > m || column <= 0 || column > n)
        return 0;
    
    if(row == m && column == n) return 1;

    if(dp[row][column] != -1) return dp[row][column]; // 이미 방문한적이 있으면 그대로 반환

    dp[row][column] = 0; // 방문 처리

    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = column + dc[i];
        if(map[row][column] > map[nr][nc]){
            dp[row][column] += dfs(nr, nc);
        }
    }

    return dp[row][column];
}

int main(void){
    cin >> m >> n;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf(" %d", &map[i][j]);
        }
    }
    
    for(int i = 1; i <= m; i++){
        fill_n(dp[i], 502, -1);
    }
    cout<<dfs(1, 1)<<'\n';
}
