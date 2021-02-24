#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define INF 1e9

int t;
bool visited[125][125]; // 방문 여부
int space[125][125]; // 탐사 공간
int d[125][125]; // 최소 값 

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<int> result;

// 특정 지점에서 특정지점으로 이동하는 최소 비용에는 역시 다익스트라
int dijkstra(int row, int column, int n){
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(-space[row][column], make_pair(row, column)));
    d[row][column] = space[row][column]; 


    while(!pq.empty()){
        int current_row = pq.top().second.first;
        int current_column = pq.top().second.second;
        int current_cost = -pq.top().first;

        pq.pop();

        visited[current_row][current_column] = true;

        for(int i = 0; i < 4; i++){ // 상 하 좌 우
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            
            // 범위가 0 ~ n - 1 이므로
            if(next_row < 0 || next_row >= n || next_column < 0 || next_column >= n){
                continue;
            }

            if(!visited[next_row][next_column]){
                int next_cost = d[current_row][current_column] + space[next_row][next_column];
                //int next_cost = current_cost + space[next_row][next_column];
                if(next_cost < d[next_row][next_column]){
                    d[next_row][next_column] = next_cost;
                    pq.push(make_pair(-next_cost, make_pair(next_row, next_column)));
                }
            }
        }
    }

    return d[n-1][n-1];
}

int main(void){
    cin>>t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        for(int row = 0; row < n; row++){
            for(int column = 0; column < n; column++){
                int x;
                cin >> x;
                space[row][column] = x;
            }
        }
        
        for(int i = 0; i < n; i++){  // 한번 사용했으므로 초기화 해줌
            fill_n(d[i], 125, INF);
            fill_n(visited[i], 125, false);
        }

        result.push_back( dijkstra(0, 0, n) ); // 각 정보를 차곡차곡 저장
    }

    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<'\n';
    }
}
