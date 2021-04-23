#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/2234

int map[51][51]; // 해당 방 위치의 벽 설치 방향
int rooms[51][51]; // 방들의 번호
int visited[51][51]; // 방들 방문 여부
int n, m;

vector<int> count_room; // 방들의 갯수
int max_room; // 최대 방 넓이 
int max_doubleRoom; // 하나의 벽을 제거했을 때 얻을 수 있는 두 방의 최대 넓이

// 남쪽, 동쪽, 북쪽, 서쪽 (*순서 중요)
int direction[4] = {8, 4, 2, 1};
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int startRow, int startColumn){
    queue<pair<int, int> > q;
    q.push(make_pair(startRow, startColumn));
    visited[startRow][startColumn] = true;
    rooms[startRow][startColumn] = count_room.size(); // 방 번호

    int sum = 1;

    while(!q.empty()){
        int current_row = q.front().first;
        int current_column = q.front().second;
        int current_wall = map[current_row][current_column];
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_direction = direction[i];
            
            if(current_wall - next_direction >= 0){ // 벽이 설치되어 있으면 스킵
                current_wall -= next_direction; // 다음 벽 설치 확인을 위해 
                continue;
            }
            
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];

            if(!visited[next_row][next_column]){
                q.push(make_pair(next_row, next_column));
                visited[next_row][next_column] = true;

                rooms[next_row][next_column] = count_room.size(); // 각 방에 번호를 붙여준다
                
                sum++; // 방의 넓이
            }
        }
    }
    return sum;
}

int main(void){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j]){
                // 1. 성에 있는 방의 개수
                count_room.push_back(bfs(i, j));
                // 2. 가장 넓은 방의 넓이
                max_room = max(max_room, count_room.back());
            }
        }
    }
    int cur_roomNum = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            
            cur_roomNum = rooms[i][j];
            for(int k = 0; k < 4; k++){
               int next_row = i + dr[k];
               int next_column = j + dc[k];
               int next_roomNum = rooms[next_row][next_column];
               
                // 상 하 좌 우 확인하며 다른 같은 방이면 스킵
                if(next_row < 1 || next_row > m || next_column < 1 || next_column > n || cur_roomNum == next_roomNum){
                    continue;
                }
                // 같은 방이 아니면 두 방의 넓이를 더하여 3번 값을 구한다.(여기서 성능 문제 발생: 이미 구한적 있는 조합도 중복해서 구함)

                // 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기 
                max_doubleRoom = max(max_doubleRoom, count_room[cur_roomNum] + count_room[next_roomNum]);
            }
        }
    }

    cout<<count_room.size()<<'\n';
    cout<<max_room<<'\n';
    cout<<max_doubleRoom<<'\n';
}
