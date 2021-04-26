#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
#define ON 1
#define OFF 0

//problem link: https://www.acmicpc.net/problem/11967

class Info_switches{
public:
    int a;
    int b;

    Info_switches(int a, int b){
        this->a = a;
        this->b = b;
    }
};

int n, m;
int map[101][101];
bool visited[101][101];
vector<Info_switches> info_switches[101][101];
int result;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main(void){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        info_switches[x][y].push_back(Info_switches(a, b));
    }

    // 시작 위치
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1)); 

    // 첫 방은 불이 켜져있는 상태
    map[1][1] = ON;
    visited[1][1] = true;
    result++; 

    while(!q.empty()){
        int current_row = q.front().first;
        int current_column = q.front().second;
        q.pop();

        // visited[current_row][current_column] = true; // 메모리 초과 원인
        
        for(int i = 0; i < info_switches[current_row][current_column].size(); i++){
            int switch_row = info_switches[current_row][current_column][i].a;
            int switch_column = info_switches[current_row][current_column][i].b;
            
            if(map[switch_row][switch_column] == OFF){ // 꺼져 있는 방의 불을 켜준다.
                map[switch_row][switch_column] = ON;
                result++; // 불 켜진 방의 갯수 증가
            }
        }
        
        for(int j = 0; j < 4; j++){ // 상 하 좌 우를 확인하면서 불이 켜진 곳만 갈수 있게 한다.
            int next_row = current_row + dr[j];
            int next_column = current_column + dc[j];
            
            if(next_row < 1 || next_row > n || next_column < 1 || next_column > n){
                continue;
            }

            if(map[next_row][next_column] == ON && !visited[next_row][next_column]){
                q.push(make_pair(next_row, next_column)); // 갈수 있는 불이 켜진 방
                visited[next_row][next_column] = true; // 갈 수 있는 곳을 미리 방문 처리해준다. (1, 1)에서 다시 출발할 경우 쓰이는 것이나 마찬가지
            }
        }

        // 현재 방에서 다른 방의 불을 켜줬으므로 더 이상 불을 킬 수 없게 한다.
        // 그리고 그 불이 켜진 방들을 갈 수 있는지 다시 처음부터 확인해야 하므로 (1, 1)로 다시 가도록 한다.
        if(info_switches[current_row][current_column].size() > 0){
            for(int i = 1; i <= n; i++){
                fill_n(visited[i], n + 1, false); // 다시 방문해야하므로
            }
            
            q.push(make_pair(1, 1)); // 처음부터 들어갈 수 있는 불 켜진 방 확인
            visited[1][1] = true; 
            info_switches[current_row][current_column].clear(); // 다시 불 못키게 함
        }
    }
    
    cout<<result<<'\n';
}
