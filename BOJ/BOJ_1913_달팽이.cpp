#include <iostream>
#include <utility>
using namespace std;

int n, m;
int map[1000][1000];
pair<int, int> coordinate;

// 위 -> 오른 -> 아래 -> 왼 -> 위 ...
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool validateRange(int row, int column, int center, int range) {
    if(row < center - range || row > center + range || column < center - range || column > center + range) {
        return false;
    }
    return true;
}

int main(void) {
    cin>>n;
    cin>>m;

    int center = n / 2; // 시작하는 중심 위치
    int num = 1; // 시작 값
    map[center][center] = num; // 중심에 시작값 넣음
    
    int current_row = center;
    int current_column = center;

    int direction = 0;
    int range = 1; // 시작 중심 위치로부터 범위

    while(!(current_row == 0 && current_column == 0)) { // 다 돌면 종료
        int prev_row = current_row;
        int prev_column = current_column;
        current_row += dr[direction];
        current_column += dc[direction];

        // 범위안에서 잘 돌지 않고 벗어나면 방향을 바꿔준다
        if(!validateRange(current_row, current_column, center, range)) {
            direction = (direction + 1) % 4; // 달팽이 모양으로 돌고 돌아

            current_row = prev_row;
            current_column = prev_column;
            continue;
        }
        
        // 자세한 설명은 생략한다.
        map[current_row][current_column] = ++num;

        // 달팽이 모양으로 한바퀴를 다 돌면 다음 한바퀴 범위 재설정
        if(current_row == center - range && current_column == center - range)
            range++;

        // 찾고자 하는 자연수 m의 위치
        if(num == m) coordinate = make_pair(current_row + 1, current_column + 1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }

    // 1의 위치는 위 while 반복문에서 찾을 수 없으므로 여기서 확인
    if (m == 1) cout<<center + 1<<' '<<center + 1<<'\n'; 
    else cout<<coordinate.first<<' '<<coordinate.second<<'\n';
}
