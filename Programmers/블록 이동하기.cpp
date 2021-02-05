#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define  WALL 1

// 상, 하, 좌, 우
int directionRow[4] = {-1, 1, 0, 0};
int directionColumn[4] = {0, 0, -1, 1};

// 회전 위 아래
int vertical[2] = {-1, 1};
// 회전 양 옆
int horizon[2] = {-1, 1};

class Drone{
    public:
    int row1;
    int column1;
    int row2;
    int column2;

    Drone(int row1, int column1, int row2, int column2){
        this->row1 = row1;
        this->row2 = row2;
        this->column1 = column1;
        this->column2 = column2;
    }
};

bool canMove(int row1, int column1, int row2, int column2, vector<vector<int> > board){
    int n = board.size();
    
    // 움직일수 있는지 확인, 참고: board 인덱스에 -1 을 해준이유는 시작 행과 열이 1부터 시작하기 때문이다
    if(row1 < 1 || row1 > n || column1 < 1 || column1 > n || board[row1-1][column1-1] == WALL ||
        row2 < 1 || row2 > n || column2 < 1 || column2 > n || board[row2-1][column2-1] == WALL){
        return false;    
    }    
    return true;
}

bool check_visited(int row1, int column1, int row2, int column2, vector<Drone> visited){
    for(int i = 0; i < visited.size(); i++){
        int visited_row1 = visited[i].row1;
        int visited_column1 = visited[i].column1;
        int visited_row2 = visited[i].row2;
        int visited_column2 = visited[i].column2;

        if(visited_row1 == row1 && visited_column1 == column1 && visited_row2 == row2 && visited_column2 == column2){
            return true;
        }
    }
    return false;
}

int bfs(int row_1, int column_1, int row_2, int column_2, vector<vector<int> > board){
    int n = board.size();
    
    queue<pair<Drone, int > >q_drone; // 드론의 모든 움직임을 담을 큐
    q_drone.push(make_pair(Drone(row_1, column_1, row_2, column_2), 0)); // 0초

    vector<Drone> visited;
    visited.push_back(q_drone.front().first); // 시작 위치 방문처리

    // 드론의 현재 위치에서 상하좌우 그리고 두 축에서의 회전 움직임이 가능한 경우를 bfs 진행한다.
    while(!q_drone.empty()){
        
        // 드론 몸통 위치
        int current_row1 = q_drone.front().first.row1;
        int current_column1 = q_drone.front().first.column1;
        int current_row2 = q_drone.front().first.row2;
        int current_column2 = q_drone.front().first.column2;
        int seconds = q_drone.front().second;
        q_drone.pop();

        if((current_row1 == n && current_column1 == n) || (current_row2  == n && current_column2 == n)){
            return seconds; // 드론 몸통중 하나라도 N x N 에 위치하면 종료
        }
        // 상 하 좌 우 움직임
        for(int i = 0; i < 4; i++){
            int next_row1 = current_row1 + directionRow[i];
            int next_column1 = current_column1 + directionColumn[i];
            int next_row2 = current_row2 + directionRow[i];
            int next_column2 = current_column2 + directionColumn[i];
            
            if(canMove(next_row1, next_column1, next_row2, next_column2, board)){ // 움직일 수 있는 곳인지 확인
                
                if(!check_visited(next_row1, next_column1, next_row2, next_column2, visited)){ // 방문한 적 없으면
                    q_drone.push(make_pair(Drone(next_row1, next_column1, next_row2, next_column2), seconds + 1));
                    visited.push_back(Drone(next_row1, next_column1, next_row2, next_column2)); // 방문 처리
                    
                }
            }
        }
        
        // 회전 - '가로' 일 경우
        if(current_row1 == current_row2){
            for(int i = 0; i < 2; i++){ // 위 아래에 대하여 세로로 회전
                // 드론의 몸통은 2개로 이루어져 있으므로 각 축을 기준으로 회전 가능 여부를 확인하자
                if(canMove(current_row1, current_column1, current_row1 + vertical[i], current_column1, board) &&
                    canMove(current_row2, current_column2, current_row2 + vertical[i], current_column2, board) ){
                    if(!check_visited(current_row1, current_column1, current_row1 + vertical[i], current_column1, visited) ){
                        q_drone.push(make_pair(Drone(current_row1, current_column1, current_row1 + vertical[i], current_column1), seconds + 1));

                        visited.push_back(Drone(current_row1, current_column1, current_row1 + vertical[i], current_column1)); // 방문 처리
                    }
                    if(!check_visited(current_row2, current_column2, current_row2 + vertical[i], current_column2, visited) ){
                        q_drone.push(make_pair(Drone(current_row2, current_column2, current_row2 + vertical[i], current_column2), seconds + 1));

                        visited.push_back(Drone(current_row2, current_column2, current_row2 + vertical[i], current_column2)); // 방문 처리
                    }
                    
                }
            }
        }

        // 회전 - '세로' 일 경우
        if(current_column1 == current_column2){
            for(int i = 0; i < 2; i++){ // 양 옆에 대하여 가로로 회전
                // 드론의 몸통은 2개로 이루어져 있으므로 각 축을 기준으로 회전 가능 여부를 확인하자
                if(canMove(current_row1, current_column1, current_row1, current_column1 + horizon[i], board) && 
                    canMove(current_row2, current_column2, current_row2, current_column2 + horizon[i], board) ){
                    if(!check_visited(current_row1, current_column1, current_row1, current_column1 + horizon[i], visited) ){
                        q_drone.push(make_pair(Drone(current_row1, current_column1, current_row1, current_column1 + horizon[i]), seconds + 1));

                        visited.push_back(Drone(current_row1, current_column1, current_row1, current_column1 + horizon[i])); // 방문 처리
                    }
                    if(!check_visited(current_row2, current_column2, current_row2, current_column2 + horizon[i], visited) ){
                        q_drone.push(make_pair(Drone(current_row2, current_column2, current_row2, current_column2 + horizon[i]), seconds + 1));

                        visited.push_back(Drone(current_row2, current_column2, current_row2, current_column2 + horizon[i])); // 방문 처리
                    }
                    
                }
            }
        }
    }
    return 0;
}

int solution(vector<vector<int> > board) {
    int answer = 0;

    answer = bfs(1, 1, 1, 2, board);
    return answer;
}
