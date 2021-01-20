#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

//problem link: https://acmicpc.net/problem/3190

#define SNAKE_BODY 2 //  뱀의 몸통
#define APPLE 3 // 사과
#define EMPTY 4 // 아무것도 없음(사과가 없음)

#define D 1 // 오른쪽으로 방향 전환
#define L -1 // 왼쪽으로 방향 전환

int map[101][101]; // 보드
queue<pair<int, int> > snake; // 뱀의 머리와 몸통(맨 마지막에 삽입된 것이 뱀의 머리이다)
vector<pair<int, int> > direction_n_time; // 경과 시간마다 전환할 방향 저장

int n, k, l; // n: 보드의 크기, k : 사과의 개수, l: 방향 변환 횟수

// (순서대로) 오른, 아래, 왼, 위 
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int index_current_direction = 0; // 현재 방향 인덱스(처음에는 오른쪽 방향)


bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int getDirection (int currentDirection, int nextDirection){  // 방향 전환
    int direction_index = currentDirection + nextDirection;
    
    if(direction_index >= 4 ){ // 위쪽 방향에서 오른쪽으로 돌면 다시 오른쪽 방향으로
        direction_index = 0;
    }
    else if(direction_index <= -1){ // 오른쪽 방향에서 왼쪽으로 돌면 다시 위쪽 방향으로
        direction_index = 3;
    }

    return direction_index;
}

bool checkGround(int row, int column){ // 뱀이 향한 곳에 사과가 있는지 확인한다
    // 가려는 곳이 보드 범위를 벗어나거나 뱀 자신의 몸통이면 false
    if(map[row][column] == SNAKE_BODY || (row > n || row < 1 || column > n || column < 1)) {
        return false;
    }
    return true;
}

void move(int row, int column){ // 뱀을 이동시킨다

    if(map[row][column] == EMPTY){ // 이동한 곳이 사과가 아니고 빈 곳이면 꼬리를 한칸 줄인다(그냥 몸통만큼 움직인다)
        int emptyRow = snake.front().first;
        int emptyColum = snake.front().second;
        snake.pop();

        map[emptyRow][emptyColum] = EMPTY;  
    }
    snake.push(make_pair(row, column)); // 한칸 이동한다
    map[row][column] = SNAKE_BODY; 
}

int startGame(int startRow, int startColumn){
    int next_row = startRow; 
    int next_column = startColumn + 1; // 처음에는 오른쪽으로 이동
    int seconds = 1; // 경과 시간
    int time_index = 0; // 첫번째 방향전환 시간 인덱스

    snake.push(make_pair(startRow, startColumn)); // 뱀의 시작위치
    map[startRow][startColumn] = SNAKE_BODY; 

    // 이동하는 좌표가 보드 안이면서 뱀의 몸통이 아닌 동안 반복
    while(checkGround(next_row, next_column)){ 
        move(next_row, next_column);

        if(direction_n_time[time_index].first == seconds){ // 방향 전환을 해야할 시간이면
            index_current_direction = getDirection(index_current_direction, direction_n_time[time_index].second); // 다음 방향 저장

            time_index++; // 다음 방향전환 시간으로 
        }

        // 다음 방향으로 한칸 이동
        next_row = next_row + dr[index_current_direction];
        next_column = next_column + dc[index_current_direction];

        seconds++; // 경과 시간 증가
    }

    return seconds;
}

int main(void){
    cin>>n;
    cin>>k;

    for(int i = 1; i <= n; i++){
        fill_n(map[i], n + 1, EMPTY);
    }
    
    for(int i = 0; i < k; i++){
        int row, column;
        cin >> row >> column;
        map[row][column] = APPLE;
    }

    cin>>l;

    for(int i = 0; i < l; i++){
        int seconds;
        char direction;

        cin >> seconds >> direction;
        
        if(direction == 'D'){
            direction_n_time.push_back(make_pair(seconds, D));
        }
        else{ // 'L' 일 경우
            direction_n_time.push_back(make_pair(seconds, L));
        }
    }

    sort(direction_n_time.begin(), direction_n_time.end()); // 작은 시간별로 처리
    
    cout<<startGame(1, 1)<<endl;
}
