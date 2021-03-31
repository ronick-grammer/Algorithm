#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1189

int r, c, k;
vector<string> map;
bool visited[5][5];

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int result;

void dfs(int row, int column, int count){
  
  if(row < 0  || row >= r || column < 0 || column >= c 
    || map[row][column] == 'T' || visited[row][column])
  {
    return;
  }

  count++; // 움직임 횟수 증가
  if(row == 0 && column == c - 1){ // 집 위치이면 종료
    if(count == k) // k 가짓수와 움직임 횟수가 같으면 그 수를 증가
      result++;
    
    return;
  }
  
  for(int i = 0; i < 4; i++){ // 상하 좌우로 움직이기
    int next_row = row + dr[i];
    int next_column = column + dc[i];
    
    visited[row][column] = true; // 현재 위치를 방문 처리하여 다음 위치에서 다시 뒤로 가는 경우가 없도록 함
    dfs(next_row, next_column, count);
    visited[row][column] = false; // 다른 방향으로 출발하는 경우를 위해 방문을 초기화함
  }
}

int main(void){
  cin >> r >> c >> k;

  for(int i = 0; i < r; i++){
    string x;
    cin >> x;
    
    map.push_back(x);
  }
  
  dfs(r - 1, 0, 0);

  cout<<result<<'\n';
}
