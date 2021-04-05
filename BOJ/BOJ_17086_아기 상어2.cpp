#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define INF 1e9

//problem link: https://www.acmicpc.net/problem/17086

// 상 하 좌 우 위왼쪽 위오른쪽 아래왼쪽 아래오른쪽
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int n, m;
int map[50][50];

int map_distance[50][50];
//bool visited[50][50];

int distance;
vector<pair<int, int> > location_shark;

void bfs(int row, int column){ // 일반적인 bfs 

  queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(0, make_pair(row, column)));
  while(!q.empty()){
    int current_row = q.front().second.first;
    int current_column = q.front().second.second;
    int current_distance = q.front().first;

    q.pop();
    for(int i = 0; i < 8; i++){
      int next_row = current_row + dr[i];
      int next_column = current_column + dc[i];
      int next_distance = current_distance + 1;

      if(next_row < 0 || next_row >= n ||  next_column < 0 || next_column >= m){
        continue;
      }

      if(next_distance < map_distance[next_row][next_column]){
        map_distance[next_row][next_column] = next_distance;
        q.push(make_pair(next_distance, make_pair(next_row, next_column)));
      }
    }
  }

}

int find_minDistance(){
  int minDis = INF;
  for(int i = 0; i < location_shark.size(); i++){ // 상어가 있는 위치들
    minDis = min(minDis, map_distance[location_shark[i].first][location_shark[i].second]);
  }

  return minDis;
}

void init_distanceMap(){
  for(int i = 0 ; i < n; i++){
    fill_n(map_distance[i], m, INF);
    //fill_n(visited[i], m, INF);
  }
}

int main(void){
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int x;
      cin >> x;
      map[i][j] = x;

      if(x == 1){ // 상어 위치 저장
        location_shark.push_back(make_pair(i, j));
      }
    }
  }

  int maxDistance = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){

      if(map[i][j] == 0){
        init_distanceMap(); // 거리 맵 초기화

        bfs(i, j); 
        maxDistance = max(maxDistance, find_minDistance()); // 최단 거리들 중에서 가장 거리가 큰 걸 찾는다

      }
    }
  }

  cout<<maxDistance<<'\n';
}
