#include <iostream>
#include <queue>
#include <utility>
using namespace std;

// 플레이어가 탈출하기까지의 최소 움직임 횟수를 구한다
// 플레이어는 항상 (1, 1) 에서 시작
// 탈출구는 항상 (n, m) 에 있다

// bfs 로 문제를 풀이하였다

int n, m;
int map[201][201];

int dr[4] = {-1, 1, 0, 0}; // 상하
int dc[4] = {0, 0, -1, 1}; // 좌우

void bfs(int startRow, int startColumn){
    queue< pair<int, int> > q;
    q.push(make_pair(startRow, startColumn)); // 플레이어 시작 위치에서 시작

    while(!q.empty()){ // q가 빌 때까지 진행

        // 현재 경로의 row 과 column 값을 구하고  현재경로에 오기까지의 움직임 횟수를 얻는다
        int current_row = q.front().first; 
        int current_column = q.front().second;
        int currentStep = map[current_row][current_column];
        q.pop();

        for(int i = 0; i < 4; i++){ // "상, 하, 좌, 우" 경로에 대한 연산 수행
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            
            if(next_row <= 0 || next_row > n || next_column <= 0 || next_column > m){ // 범위를 초과하면 다시 시작
                continue;
            }
            
            int nextStep = map[next_row][next_column];
            if(nextStep == 1){ // 1이라는 건 방문한적이 없다는 것이다 
                
                map[next_row][next_column] = currentStep + nextStep; // 현재 경로까지 움직였던 횟수 + 1

                q.push(make_pair(next_row, next_column));
            }

        }
    }
}

int main(void){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(1, 1); // bfs 진행

    cout<<map[n][m]<<endl;
}
