#include <iostream>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/16918

vector<vector<char> > map(200, vector<char> (200, '.'));
int r, c, n;

// 상 하 좌 ㅈ우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 포탄을 터트린 뒤의 맵을 반환
vector<vector<char> > explode(vector<vector<char> > map_bombsInstalled){
  vector<vector<char> > map_exploded = map_bombsInstalled;
  for(int row = 0; row < r; row++){
    for(int column = 0; column < c; column++){
      if(map[row][column] == 'O'){ // 먼저 설치한 포탄이 있다면
        map_exploded[row][column] = '.'; // 그 위치의 포탄을 터트리고
        for(int k = 0; k < 4; k++){ // 상 하 좌 우 한칸씩 위치한 곳을 터트린다
          int next_row = row + dr[k];
          int next_column = column + dc[k];

          if(next_row < 0 || next_row >= r || next_column < 0 || next_column >= c){
            continue;
          }
          
          map_exploded[next_row][next_column] = '.';
        }
      }
    }
  }
  return map_exploded;
}

int main(void){
  
  cin >> r >> c >> n;
  
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      char x;
      cin >> x;
      map[i][j] = x;
    }
  }
  int bombsInstalled_sec = 1; // 첫 포탄들이 설치된 시작 초는 1초이다
  for(int sec = 2; sec <= n; sec++){ 
    
    bombsInstalled_sec++; 
    
    if(bombsInstalled_sec == 3){ // 3초 때에 포탄 터짐
      vector<vector<char> > map_bombsInstalled(r, vector<char> (c, 'O')); // 우선 맵 전체에 새 포탄들을 설치
      map = explode(map_bombsInstalled); // 그리고 나서 기존에 설치한 포탄을 터트린다
      
      bombsInstalled_sec = 1; // 포탄을 새로 설치했으므로 1초 경과
    }
  }
  
  if(n % 2 == 0){ // 짝수 초는 언제나 맵 전체가 전부 포탄이 설치 되어 있다
    map = vector<vector<char> > (r, vector<char>(c, 'O'));
  }

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout<<map[i][j];
    }
    cout<<'\n';
  }
}
