#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18428

int n;
bool detected; // 학생이 발견되었는지 여부

char map[7][7]; // 오리지널 맵
char temp_map[7][7]; // 오리지널 맵에 벽들이 설치 될 맵

// 순서대로 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

pair<int, int> wall_locations[3]; // 벽들이 설치될 위치 저장

bool dfs(int row, int column, int index_direction){
    if(temp_map[row][column] == 'S'){ // 한명이라도 발견되면 종료
        return detected = true;
    }
    // 맵의 범위를 넘어가거나 '선생'이거나 '벽'이면 종료
    if(row < 1 || row > n || column < 1 || column > n || temp_map[row][column] == 'O' || temp_map[row][column] == 'T'){
       
        return detected = false;
    }

    // 한방향으로만 쭉 체크한다
    return dfs(row + dr[index_direction], column + dc[index_direction], index_direction);
}

// 벽이 설치될 수 있는 위치인지 확인한다
bool checkOverlap(vector<bool> visited){
    int index = 0;

    for(int i = 0; i < visited.size() ; i++){

        if(visited[i]){
            // 참고: 모든 행과 열은 1부터 시작한다. 그렇기에 + 1
            int row = (i / n) + 1; // 행 계산
            int column = (i % n) + 1; // 열 계산

            // 빈공간이 아니면
            if(temp_map[row][column] == 'O' || temp_map[row][column] == 'T' || temp_map[row][column] == 'S'){
                return false;
            }
            else{ // 빈공간이면 설치할 위치 저장
                wall_locations[index].first = row;
                wall_locations[index].second = column;
                index++;
            }
        }
    }

    return true;
}

int main(void){
    vector<pair<int, int> > teacher_locations;

    cin>>n;

    for(int row = 1; row <= n; row++){
        for(int column = 1; column <= n; column++){
            char x;
            cin >> x;
            
            map[row][column] = x;
            temp_map[row][column] = x;

            if(x == 'T'){
                teacher_locations.push_back(make_pair(row, column)); // 선생들의 위치를 저장
            } 
        }
        
    }

    vector<bool> visited(n*n);
    fill(visited.end() - 3, visited.end(), true); // next_permutation() 사용을 위해 오름 차순 

    do{ // 벽이 설치 될수 있는 모든 경우의 수만큼 진행한다
        detected = false;
 
        if(checkOverlap(visited)){ // 벽이 설치될 수 있다면
            for(int i = 0; i < 3; i++){ // 벽을 설치해준다
                int row = wall_locations[i].first;
                int column = wall_locations[i].second;

                temp_map[row][column] = 'O';
            }

            for(int i = 0; i < teacher_locations.size(); i++){ // 모든 선생에 대하여
                int row = teacher_locations[i].first;
                int column = teacher_locations[i].second;

                // 각각 상 하 좌 우, 한방향으로 가는 dfs 를 진행한다
                for(int index_direction = 0; index_direction < 4; index_direction++){
                    if(dfs(row + dr[index_direction] , column + dc[index_direction], index_direction)){
                        break; // 발견되었으면 반복에서 나간다
                    }
                }

                // 학생이 한명이라도 한명의 선생에게 발견되었으면 이번 위치에 설치된 벽들의 맵은 더이상 볼 필요 없다.
                if(detected){ 
                    break;
                }
            }

            if(!detected){ // 발견된 학생이 한명도 없다면
                cout<<"YES"<<endl;
                return 0; // 바로 종료
            }

            for(int row = 1; row <= n; row++){ // map 다시 원상태로 복구
                for(int column = 1; column <= n; column++){
                    temp_map[row][column] = map[row][column];
                }
            }
        }
    }while(next_permutation(visited.begin(), visited.end()));

    // 발견된 학생이 한명이라도 있었으므로 
    cout<<"NO"<<endl;
}
