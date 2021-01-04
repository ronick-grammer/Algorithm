#include <iostream>
using namespace std;

// 북, 동, 남, 서
int direction_row[4] = {-1, 0, 1, 0};
int direction_column[4] = { 0, 1, 0, -1};

// 맵
int map[51][51];

int getDirection(int x){
    int d = x - 1; // 시계 반대 방향으로 회전

    if(d == -1){ // 서쪽 - > 북쪽 회전
        d = 3;
    }

    return d;
}

int main(void){
    int n, m; // map N x M
    int a, b, d; // a: 행, b: 열, d: 현재 방향
    int count_turning = 0;
    int count_visited; 

    cin >> n >> m;
    cin >> a >> b >> d;

    for(int i = 0; i < n; i++){ // 맵의 크기만큼 '1': 바다 '0': 육지 를 입력한다
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    map[a][b] = 1; // 첫 위치는 방문처리
    count_visited = 1; // 캐릭터는 처음에 육지에 위치하므로 최소 방문횟수는 1이다

    while(1){
        int d = getDirection(d); // 회전한다
        count_turning++; // 회전 수 증가

        // 회전하고 한칸 전진했을때 좌표 저장
        int nr = a + direction_row[d];  
        int nc = b + direction_column[d];

        // 그 좌표가 육지라면 고고
        if(map[nr][nc] == 0){
            a = nr; 
            b = nc;
            
            map[nr][nc] = 1; // 바다로 만들어 방문 처리 해준다
            count_turning = 0; // 돌아이 횟수를 0 으로 만든다
            count_visited++; // 방문횟수 증가
        }

        if(count_turning == 4){ // 만약 네번 다 돌았으면 == 돌아봤는데 다 바다더라

            // 방향 유지한채로 뒤로 한칸 후진
            nr = a - direction_row[d];
            nc = b - direction_column[d];    

            if(map[nr][nc] == 1){ // 한칸 후진했는데 바다이거나 방문한거면 멈춘다
                break;
            }
            
            // 그렇지 않으면 이동한다
            a = nr;
            b = nc;
            count_turning = 0;
        }
    }

    cout<<count_visited<<endl;
}
