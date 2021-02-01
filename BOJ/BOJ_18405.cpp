#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18405

int n, k;
int s, x, y;

// 순서대로 상, 하, 좌, 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int map[201][201];
vector<pair<int, pair<int, int> > > v; // 바이러스 종류 번호, (행, 열)
int currentCount_perSecond = 0; // 1 초마다 증식할 바이러스의 수

void bfs(){
    queue<pair<int, pair<int, int> > > q;
    int nextCount_perSocond = 0;
    int currentSeconds = 0; 

    for(int i = 0; i < v.size(); i++){
        int virusNumber = v[i].first;
        int row = v[i].second.first;
        int column = v[i].second.second;

        q.push(make_pair(virusNumber, make_pair(row, column)));
    }

    while(!q.empty() && currentSeconds != s){ // 큐가 비어 있지 않으면서 s초 동안 반복
        int virusNumber = q.front().first;
        int current_row = q.front().second.first;
        int current_column = q.front().second.second;
        q.pop();
        currentCount_perSecond--; // 1초마다 증식하는 바이러스 갯수를 1개씩 빼준다

        for(int i = 0; i < 4; i++){ // 상 하 좌 우 감염시키기
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];

            // 범위를 초과했거나 해당 위치에 이미 빈칸이 아니면 무시한다
            if(next_row < 1 || next_row > n || next_column < 1 || next_column > n || map[next_row][next_column] != 0){
                continue;
            }
           
            map[next_row][next_column] = virusNumber;
            q.push(make_pair(virusNumber, make_pair(next_row, next_column)));
            nextCount_perSocond++; // 다음 1초에 증식할 바이러스 수를 하나씩 증가시킨다
        }

        if(currentCount_perSecond == 0){ // 1초 동안 바이러스가 전부 증식했으므로
            currentSeconds++; // 1초가 카운트 된다
            currentCount_perSecond = nextCount_perSocond; // 그리고 이제 다음 1초 동안 증식할 바이러스 수를 새로 저장한다
            nextCount_perSocond = 0;
        }
    }
}

int main(void){
    cin >> n >> k;

    for(int row = 1; row <= n; row++){
        for(int column = 1; column <= n; column++){
            int x;
            cin >> x;

            if(x != 0){
                v.push_back(make_pair(x, make_pair(row, column)));
                currentCount_perSecond++; // 첫 1초 동안 증식할 바이러스 수
            }

            map[row][column] = x;
        }
    }

    cin >> s >> x >> y;

    sort(v.begin(), v.end());  // 바이러스 번호가 가장 낮은 순으로 오름차순
    bfs();

    cout<<map[x][y]<<endl;
}
