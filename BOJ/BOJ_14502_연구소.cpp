#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/14502

int n, m;
int lab[8][8]; // 오리지널 랩
int tempLab[8][8]; // 오리지널 랩에서 벽들이 설치될 임시 랩
pair<int, int> wall_location[3]; // 벽이 설치될 위치를 담는 변수


void dfs(int row, int column){ // 바이러스를 퍼트린다
    
    if(row < 0 || row >= n || column < 0 || column >= m){ // 범위를 벗어나면 종료
        return;
    }

    if(tempLab[row][column] == 0){ // 빈 공간이면 바이러스가 퍼질수 있다
       tempLab[row][column] = 2;

        dfs(row + 1, column);
        dfs(row - 1, column);
        dfs(row, column + 1);
        dfs(row, column - 1);
    }
}

bool checkOverlap(vector<bool> visited){ // 벽이 설치되는 위치가 바이러스나 다른 벽과 겹치는지 확인한다
    int index = 0;

    for(int i = 0 ; i < visited.size(); i++){
        if(visited[i] == true){
            int row = i / m; // 행 계산
            int column = i % m; // 열 계산
            if(tempLab[row][column] == 2 || tempLab[row][column] == 1){ // 겹치면 false 반환
                return false;
            }
            else{
                // 벽이 설치 될 위치 기억
                wall_location[index].first = row; 
                wall_location[index].second = column;
                index++;
            }
        }
    }
    return true;
}

int main(void){
    cin >> n >> m;
    for(int row = 0; row < n; row++){
        for(int column = 0; column < m; column++){
            int x;
            cin >> x;
            lab[row][column] = x;
            tempLab[row][column] = x;
        }
    }

    vector<bool> visited(n*m);

    // next_permutation() 메서드의 마지막 순열 결과는 내림차순이다.
    // 따라서 바로 밑처럼 초기화를 하면 "1110000..."" 이 되는데 
    // 이렇게 시작부터 내림차순으로 next_permutation() 을 실행하면, 순열을 다 만들었다고 보고 
    // 더이상의 순열을 생성하지 않게 된다. 따라서 오름차순으로 "00000...111" 초기화를 실시해야 한다.
    //fill(visited.begin(), visited.begin() + 3, true); 
    fill(visited.end() - 3, visited.end(), true);
    int result = 0;

    do { // N x M 랩에 세 개의 벽이 설치 될 수 있는 모든 경우의 수만큼 진행한다
        int sum = 0;
        if(checkOverlap(visited)){ // 세곳의 위치에 벽이 설치 될 수 있다면
            for(int i = 0; i < 3; i++){ // 그 세곳의 위치에 벽을 설치한다
                int row = wall_location[i].first;
                int column = wall_location[i].second;
                tempLab[row][column] = 1;
            }

            for(int row = 0; row < n; row++){ // 그리고 바이러스를 퍼트린다
                for(int column = 0; column < m; column++){
                    if(tempLab[row][column] == 2){
                        dfs(row + 1, column);
                        dfs(row - 1, column);
                        dfs(row, column + 1);
                        dfs(row, column - 1);
                    }
                }
            }

            for(int row = 0; row < n; row++){  // 바이러스가 퍼지고 난 빈공간의 갯수를 샌다
                for(int column = 0; column < m; column++){
                    if(tempLab[row][column] == 0){
                        sum++;
                    }
                }
            }

            for(int row = 0; row < n; row++){ // 랩을 초기화 한다
                for(int column = 0; column < m; column++){
                    tempLab[row][column] = lab[row][column];
                }
            }

            result = max(result, sum); // 빈공간의 최대 갯수를 저장해준다
        }

    } while (next_permutation(visited.begin(), visited.end()));
    
    cout<<result<<endl;
}
