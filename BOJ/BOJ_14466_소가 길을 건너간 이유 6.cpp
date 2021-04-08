#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/14466

int n, k, r;
vector<pair<int, int> > map[101][101];
bool visited[101][101];
vector<pair<int, int> > cowLocation;

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool checkBridge(int rowA, int columnA, int rowB, int columnB){
  for(int i = 0; i < map[rowA][columnA].size(); i++){
    int row = map[rowA][columnA][i].first;
    int column = map[rowA][columnA][i].second;

    if(row == rowB && column == columnB){ // 두 지점사이 다리가 있으면 true
      return true;
    }
  }
  return false;
}

bool bfs(int cowA, int cowB){
  queue<pair<int, int> > q;
  q.push(cowLocation[cowA]);
  visited[cowLocation[cowA].first][cowLocation[cowA].second] = true;

  while(!q.empty()){
    int current_row = q.front().first;
    int current_column = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int next_row = current_row + dr[i];
      int next_column = current_column + dc[i];

      if(next_row < 1 || next_row > n || next_column < 1 || next_column > n){
        continue;
      }

      if(!visited[next_row][next_column]){ // 방문 한 곳이 아니라면
        // 두 지점사이에 다리가 있으면 스킵
        if(checkBridge(current_row, current_column, next_row, next_column)){
          continue;
        }
        // 다리가 연결되어있지 않은 도착점이라면 true
        if(next_row == cowLocation[cowB].first && next_column == cowLocation[cowB].second){
          return true;
        }
        
        q.push(make_pair(next_row, next_column));
        visited[next_row][next_column] = true;
      }
    }
  }
  // 전부 돌아봤는데도 만나지 못했으므로 false
  return false;
}

void initVisited(){
  for(int i = 1; i <= n; i++){
    fill_n(visited[i], n + 1, false);
  }
}

int main(void){
  cin >> n >> k >> r;

  for(int i = 0 ; i < r; i++){
    int rowA, columnA, rowB, columnB;
    cin >> rowA >> columnA >> rowB >> columnB;

    // 두 지점에 다리를 연결해줌
    map[rowA][columnA].push_back(make_pair(rowB, columnB));
    map[rowB][columnB].push_back(make_pair(rowA, columnA));
  }

  for(int i = 0; i < k; i++){
    int row, column;
    cin >> row >> column;
    cowLocation.push_back(make_pair(row, column));
  }

  int result = 0;
  for(int i = 0; i < k - 1; i++){
    for(int j = i + 1; j < k; j++){
      initVisited();
      if(!bfs(i, j)) result++;
    }
  }

  cout<<result<<'\n';
}
