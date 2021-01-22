#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define GIDOONG 3
#define BO 4
#define EMPTY 0

int board[101][101]; 
vector<vector<int> > result; 

bool compare(vector<int> a, vector<int> b){
    if(a[0] !=  b[0]){ // x 좌표가 같지 않으면
        return a[0] < b[0];
    }
    else if(a[1] != b[1]){ // y 좌표가 같지 않으면
        return a[1] < b[1];
    }
    else{ 
        return a[2] < b[2]; // '기둥'이 '보' 보다 앞으로 온다
    }
}

// 보드에 해당 좌표의 구조물을 설치만 해준다
void insertIntoBoard(int x, int y, int kind){
    vector<int> coordinate;

    if(kind == 0){ // '기둥' 이면
        board[x][y+1] += GIDOONG;
    }else if(kind == 1){ // '보' 이면
        board[x][y] += BO;
        board[x+1][y] += BO;
    }
}

//좌표에 설치된 구조물을 제거한다
void removeFromBoard(int x, int y, int kind){
    if(kind == 0){ // '기둥' 이면
        board[x][y+1] -= GIDOONG;
    }else if(kind == 1){ // '보' 이면
        board[x][y] -= BO;
        board[x+1][y] -= BO;
    }
}

// 구조물이 설치된 좌표 정보를 저장한다
void push_info(int x, int y, int kind){
    vector<int> coordinate;

    coordinate.push_back(x);
    coordinate.push_back(y);
    coordinate.push_back(kind);
    
    result.push_back(coordinate);
}

// 구조물이 설치가 가능한지 여부를 확인
bool canInsert(int n, int x, int y, int kind){
    if(kind == 0){ // '기둥' 이면
        if(y >= 0 && (y + 1) <= n){ // 벽면을 벗어나지 않으면 
            // '기둥'은 바닥 위에 있거나 다른 기둥위에 있거나 보의 한쪽 끝 부분 위에 있으면 설치가 가능하다
            if(y == 0 || board[x][y] >= GIDOONG){ // 참고: GIDOONG 의 값은 3 이고 BO 의 값은 4이다
                return true;
            }
        }
    }else if (kind == 1){ // '보' 이면
        if(x >= 0 && (x + 1) <= n){ // 벽면을 벗어나지 않으면
            // '보'는 바닥 위가 아니면서 한쪽 끝부분이 기둥위에 있거나 양쪽 끝 부분이 다른 보와 동시에 연결되어 있으면 설치가 가능하다
            if(y != 0 && ((board[x][y] == GIDOONG || board[x + 1][y] == GIDOONG) || 
             (board[x][y] == GIDOONG + BO || board[x+1][y] == GIDOONG + BO) ||  
             (board[x][y] >= BO && board[x + 1][y] >= BO))){
                return true;
            }
        }
    }
    return false;
}

void remove(int n, int x, int y, int kind){

    for(int i = 0; i < result.size(); i++){
        if(x == result[i][0] && y == result[i][1] && kind == result[i][2]){
            result.erase(result.begin() + i); // 지정 좌표와 구조물 정보 삭제
            removeFromBoard(x, y, kind); // 보드의 지정 좌표에 설치되어 있는 구조물 제거

            for(int j = 0; j < result.size(); j++){ // 이제 남은 구조물들이 설치가 유지 되는지 확인
                int x_position = result[j][0];
                int y_position = result[j][1];
                int k = result[j][2];
                
                removeFromBoard(x_position, y_position, k); // 해당 좌표에 설치되어 있는 구조물 제거
                if(!canInsert(n, x_position, y_position, k)){ // 처음에 삭제한 구조물이 없으면 설치 유지가 안되는 경우 삭제 불가능하다
                    insertIntoBoard(x, y, kind); // 처음 삭제했던 구조물을 다시 원상복구 시킨다
                    push_info(x, y, kind); // 처음 삭제했던 구조물의 정보를 다시 넣는다

                    insertIntoBoard(x_position, y_position, k);
                    return;
                }
                insertIntoBoard(x_position, y_position, k);
            }
            return;
        }
    }
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;

    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int kind = build_frame[i][2];
        int option = build_frame[i][3];
        
        if(option == 0){ // 삭제
            remove(n, x, y, kind);
        }

        if(option == 1) { // 설치
            if(canInsert(n, x, y, kind)){
                insertIntoBoard(x, y, kind);
                push_info(x, y, kind);
            }
        }
    }

    sort(result.begin(), result.end(), compare); // 정렬
    return result;
}
