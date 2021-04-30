#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/8972

int r, c;
char board [101][101];

string direction_str;
int direction[100];
// 인덱스 [0] 은 사용하지 않는다
int dr[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

pair<int, int> myPos;
vector<pair<int, int> > krajXPos;

int count_turn;
bool gameOver;

int visited[101][101];

void gameStart(){
    for(int i = 0; i < direction_str.size(); i++){
        int next_my_row = myPos.first + dr[direction[i]];
        int next_my_column = myPos.second + dc[direction[i]];

        count_turn++; // 이동한 횟수
        
        if(board[next_my_row][next_my_column] == 'R'){ // 로봇 만나면 게임오버
            gameOver = true;
            return;
        }
        // 이동
        board[myPos.first][myPos.second] = '.';
        myPos.first = next_my_row;
        myPos.second = next_my_column;
        board[next_my_row][next_my_column] = 'I';
        
        for(int j = 0; j < krajXPos.size(); j++){
            pair<pair<int, int>, int > minPos = make_pair(make_pair(0, 0), 1e9);
            
            for(int k = 1; k < 10; k++){ // 아홉가지 방향
                int next_X_row = krajXPos[j].first + dr[k];
                int next_X_column = krajXPos[j].second + dc[k];

                if(next_X_row < 1 || next_X_row > r || next_X_column < 1 || next_X_column > c || k == 5)
                    continue;
                
                int distance = abs(next_my_row - next_X_row) + abs(next_my_column - next_X_column);
                if(minPos.second > distance) // 주인공 로봇과 가장 가까운 다음 좌표 저장
                    minPos = make_pair(make_pair(next_X_row, next_X_column), distance);
                
            }

            if(board[minPos.first.first][minPos.first.second] == 'I'){ // 주인공 로봇과 만나면 게임 오버
                gameOver = true;
                return;
            }
          
            board[krajXPos[j].first][krajXPos[j].second] = '.'; // 우선 비어있게 함
           
            // 이동할 좌표들 저장
            krajXPos[j].first = minPos.first.first;
            krajXPos[j].second = minPos.first.second;
    
            visited[minPos.first.first][minPos.first.second]++; // 다른 아두이노와 겹치는지 확인
        }

        vector<pair<int, int> > remain; // 폭발 후 남을 미친 아두이노들
        for(int j = 0; j < krajXPos.size(); j++){
            int row = krajXPos[j].first;
            int column = krajXPos[j].second;

            if(visited[row][column] == 1){ // 한 곳에 겹치지 않는 미친 아두이노만 이동 시키고 저장
                board[row][column] = 'R';
                remain.push_back(make_pair(row, column));
            }
        }

        for(int j = 0; j <= 100; j++){ // 방문횟수 초기화
            fill_n(visited[j], 101, 0);
        }
        krajXPos = remain; // 폭발후 남은 미친 아도이노들 좌표만 저장
    }
}

int main(void){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'R')
                krajXPos.push_back(make_pair(i, j)); // 미친 아두이노들 좌표
            else if(board[i][j] == 'I')
                myPos = make_pair(i, j); // 주인공 좌표
        }
    }

    cin>>direction_str;
    for(int i = 0; i < direction_str.size(); i++){
        direction[i] = direction_str[i] - '0'; // 숫자로 변환
    }

    gameStart();
    if(gameOver)
        cout<<"kraj "<<count_turn<<'\n';
    else{
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                cout<<board[i][j];
            }
            cout<<'\n';
        }
    }
}
