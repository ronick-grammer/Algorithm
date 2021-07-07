//problem link: https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
int map[101][101];
int minDistance[101][101];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

bool validate_range(int row, int column){
    if(row < 1 || row > n || column < 1 || column > m)
        return false;
    
    return true;
}

int bfs(int start_row, int start_column) {
    queue<pair<int, pair<int, int> > > q;

    q.push(make_pair(1, make_pair(start_row, start_column)));
    minDistance[1][1] = 1; // 첫 출발부터 1칸 움직인걸로 본다.

    while(!q.empty()){
        int current_row = q.front().second.first;
        int current_column = q.front().second.second;
        int current_cost = q.front().first;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            int next_cost = current_cost + 1;

            // 미로 범위와 이동할 수 있는 칸인지 체크
            if(!validate_range(next_row, next_column) || map[next_row][next_column] == 0)
                continue;
            
            if(minDistance[next_row][next_column] > next_cost){ // 가장 적은 칸 수를 갱신시켜준다.
                minDistance[next_row][next_column] = next_cost;
                q.push(make_pair(next_cost, make_pair(next_row, next_column)));
            }
        }
    }

    return minDistance[n][m];
}

int main(void){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        fill(minDistance[i], minDistance[i] + m + 1, 1e9);
    }
    
    cout<<bfs(1, 1)<<'\n';
}
