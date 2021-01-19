#include <iostream>
#include <vector>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/60059?language=cpp

vector<vector<int> > rotateMatrix(vector<vector<int> > key){ // 열쇠 회전(2차원 배열 시계 방향으로 90 도 회전)
    int size_row = key.size(); // 열쇠의 행 길이
    int size_column = key[0].size(); // 열쇠의 열 길이

    vector<vector<int> > key_rotated(size_row);
    for(int i = 0; i < size_row; i++){ // 회전 가즈아!!!
        for(int j = 0; j < size_column; j++){
            key_rotated[i].push_back(key[size_row - j - 1][i]);
        }
    }
    return key_rotated;
}

bool checkLock(vector<vector<int> > lock, int n){ // 자물쇠 부분이 전부 1인지(열쇠가 자물쇠를 열수 있는지) 확인
    int size_row = lock.size();
    int size_column = lock[0].size();

    for(int row = 0; row < n; row++){ // 가운데에 있는 자물쇠가 전부 1인지 확인
        for(int column = 0; column < n; column++){
            if(lock[row + n][column + n] != 1){ // 하나라도 맞지 않으면 false 리턴
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size(); // 자물쇠의 사이즈 n x n
    int m = key.size(); // 열쇠의 사이즈 m x m

    // 열쇠의 모든 부분과 자물쇠의 부분을 비교하려면 열쇠가 놓일 영역을 만들어주기 주기 위해 자물쇠의 영역을 확장해준다
    vector<vector<int> > newLock(n * 3, vector<int>(n * 3)); 

    for(int i = 0; i < n; i++){ // 확장된 자물쇠 영역에 자물쇠를 가운데에 위치 시킨다
        for(int j = 0; j < n; j++){
            newLock[i + n][j + n] = lock[i][j]; // 가운데에 자물쇠를 놓는다
        }
    }

    vector<vector<int> > lockAndKey = newLock; //확장된 자물쇠와 열쇠를 끼어넣기 위한 벡터

    for(int count_rotation = 0; count_rotation < 4; count_rotation++){ // 네번 회전

        key = rotateMatrix(key); // 시계방향으로 90도 회전시킨다

        // 1부터 시작하는 이유는 불필요하게 0 부터 시작하면 열쇠와 자물쇠가 겹치지 않기 때문이다
        // 0 부터 시작 하면 처음부터 겹친 상태로 시작할 수 있다
        for(int i = 1; i < n * 2; i++){   // 열쇠는 가운데에 놓인 자물쇠의 영역을 다 벗어날 때까지만 진행한다
            for(int j = 1; j < n * 2; j++){

                for(int row = 0; row < m; row++){ // 확장된 자물쇠에 회전된 키를 한칸씩 왼쪽 위에서 오른쪽 아래로 넣어준다
                    for(int column = 0; column < m; column++){
                        lockAndKey[i + row][j + column] += key[row][column]; 
                    }
                }
                
                if(checkLock(lockAndKey, n)) // 열쇠가 자물쇠를 열 수 있는지 확인
                {
                    return true;
                }
                lockAndKey = newLock; // 다시 자물쇠를 초기화 시킨다
            }
        }
    }
    
    return false;
}
