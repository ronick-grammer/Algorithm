#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define EMPTY 0;
#define SHARK 9;
#define SMALLEST_FISH 1
#define BIGGIEST_FISH 6

int n;
int map[20][20]; // 아기상어와 물고기가 있는 맵
int map_seconds[20][20]; // 한칸씩 상하좌우로 이동할 때마다 1초식 증가할 맵 
int size_shark = 2; // 아기상어의 처음 크기
int count_eat; // 아기상어가 현재 크기에서 먹은 물고기의 수
vector<pair<int, pair<int, int> > > location_eatiblefish; // row, column, seconds;

//상, 하, 좌, 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.second.second == b.second.second){ // 가장 가까운 물고기가 여러 마리라면
        if(a.first == b.first){ // 가장 위에 있는 물고기가 여러 마리라면
            return a.second.first < b.second.first; // 그 위의 위치에서 가장 왼쪽의 위치대로 정렬
        }
        else{ // 아니라면
            return a.first < b.first; // 가장 위에 있는 위치대로 정렬
        }
    }
    else{ // 아니라면
        return a.second.second < b.second.second; // 가장 가까운 하나의 물고기의 위치대로 정렬
    }
}

void bfs(int startRow, int startColumn, int startSeconds){

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(startRow, make_pair(startColumn, startSeconds)));

    while(!q.empty()){
        int current_row = q.front().first;
        int current_column = q.front().second.first;
        int current_seconds = q.front().second.second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            int next_seconds = current_seconds + 1;
            
            // 범위를 벗어나거나 자신보다 큰 물고기의 위치에는 갈수 없다.
            if(next_row < 0 || next_row >= n || next_column < 0 || next_column >= n || size_shark < map[next_row][next_column]){
                continue;
            }
            
            if(map_seconds[next_row][next_column] == 0){ // 방문한 적이 없으면 
                if(size_shark > map[next_row][next_column]  // 자기보다 작은 물고기를 먹을 수 있다면 그 위치 저장
                    && map[next_row][next_column] >= SMALLEST_FISH && map[next_row][next_column] <= BIGGIEST_FISH){
                    
                    location_eatiblefish.push_back(make_pair(next_row, make_pair(next_column, next_seconds))); // 먹을 물고기 위치 기억
                }
                // 그냥 빈칸이거나 아기상어와 크기가 같은 물고기거나 크기가 작은 물고기일때는 그 위치에 갈수 있다
                map_seconds[next_row][next_column] = next_seconds;
                q.push(make_pair(next_row, make_pair(next_column, next_seconds)));
            }
        }
    }
    
}

int main(void){
    int startRow;
    int startColumn;
    cin>>n;

    for(int row = 0; row < n; row++){
        for(int column = 0; column < n; column++){
            int x;
            cin >> x;
            map[row][column] = x;
            
            if(map[row][column] == 9){ // 상어 위치 
                startRow = row;
                startColumn = column;
            }
        }
    }

    int seconds = 0; // 처음은 0초부터 시작
    map[startRow][startColumn] = SHARK; // 상어의 첫 위치
    do
    {
        location_eatiblefish.clear();
        for(int i = 0; i < 20; i++){
            fill_n(map_seconds[i], 20, 0); // 초 초기화
        }

        bfs(startRow, startColumn, seconds); // bfs 진행
        
        if(location_eatiblefish.size() != 0){ // 잡아 먹은 물고기가 하나 이상이면

            map[startRow][startColumn] = EMPTY; // 원래 아기 상어가 있던 위치를 빈자리로 만듬(잡아먹으러 이동할꺼니까)
            
            // 어디로 이동할지 결정해야 하므로 특정 기준으로 정렬
            sort(location_eatiblefish.begin(), location_eatiblefish.end(), compare); 

            startRow = location_eatiblefish[0].first; // 다음 행 위치
            startColumn = location_eatiblefish[0].second.first; // 다음 열 위치
            seconds = location_eatiblefish[0].second.second; // 다음 초

            map[startRow][startColumn] = SHARK; // 잡아먹음
            
            // 물고기 하나를 먹었으므로 먹은 갯수 증가
            count_eat++;
            if(count_eat == size_shark){
                size_shark++;
                count_eat = 0;
            }
        }

    } while (location_eatiblefish.size() != 0); // 잡아먹을 물고기가 하나도 없을 경우 종료
    
    cout<<seconds<<'\n';
}
