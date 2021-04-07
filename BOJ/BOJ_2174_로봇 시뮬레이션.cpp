#include <iostream>
#include <vector>
using namespace std;

/problem link: https://www.acmicpc.net/source/28108542

int a, b;
int n, m;

int map[101][101];
// <- 북 <-> 동 <-> 남 <-> 서 ->
char directions[4] = {'N', 'E', 'S', 'W'};
int directionRow[4] = {-1, 0, 1, 0};
int directionColumn[4] = {0, 1, 0, -1};

class Robot{
public:
  int row; // 현재 위치 행
  int column; // 현재 위치 열
  int dr; // 현재 행 방향
  int dc; // 현재 열 방향
  int direction; // 현재 방향

  Robot(int row, int column, int dr, int dc, int direction){
    this->row = row;
    this->column = column;
    this->dr = dr;
    this->dc = dc;
    this->direction = direction;
  }

  void rotate(int x){ // 회전 방향 x, -1 : 왼쪽, 1 : 오른쪽
    this->direction += x; 
    if(this->direction == -1){ // 왼쪽으로 계속 회전
      this->direction = 3;
    }
    if(this->direction == 4){ // 오른쪽으로 계속 회전
      this->direction = 0;
    }

    this->dr = directionRow[this->direction]; // 직진 방향 행
    this->dc = directionColumn[this->direction]; // 직진 방향 열
  }

  void forward(){ // 현재 방향으로 직진
    row += this->dr; 
    column += this->dc;
  }
};

class Order{
public:
  int robotNumber; // 로봇 번호
  char option; // 명령 옵션
  int repeat; // 반복 횟수

  Order(int robotNumber, char option, int repeat){
    this->robotNumber = robotNumber;
    this->option = option;
    this->repeat = repeat;
  }
};

vector<Robot> robots;
vector<Order> orders;

int main(void){
  cin >> a >> b;

  cin >> n >> m;
  for(int i = 0; i < n; i++){ 
    int row, column;
    char direction;
    int directionIndex;
    cin >> column >> row >> direction; // 행과 열의 순서를 바꿔서 입력 받는다

    int dRow, dColumn;
    for(int j = 0; j < 4; j++){
      if(direction == directions[j]){ // 입력한 방향으로 설정
        dRow = directionRow[j];
        dColumn = directionColumn[j];
        directionIndex = j;
        break;
      }
    }
    map[b - row][column - 1] = i + 1; // 로봇의 위치 설정

    robots.push_back(Robot(b - row, column - 1, dRow, dColumn, directionIndex));
  }

  for(int i = 0; i < m; i++){
    int robotNumber, repeat;
    char option;

    cin >> robotNumber >> option >> repeat;

    orders.push_back(Order(robotNumber, option, repeat));
  }

  for(int i = 0; i < orders.size(); i++){
    int robotIndex = orders[i].robotNumber - 1; // 각 로봇의 인덱스
    for(int j = 0; j < orders[i].repeat; j++){ // 명령의 반복횟수
      int prevRow = robots[robotIndex].row;
      int prevColumn = robots[robotIndex].column;

      if(orders[i].option == 'L'){ // 왼쪽으로 회전
        robots[robotIndex].rotate(-1);
      }
      else if(orders[i].option == 'R'){ // 오른쪽으로 회전
        robots[robotIndex].rotate(1);
      }
      else {// forward
        robots[robotIndex].forward();
        
        // 직진을 하고 나서 범위를 벗어나는지 여부를 먼저 확인해야 한다
        if(robots[robotIndex].row < 0 || robots[robotIndex].row >= b
          || robots[robotIndex].column < 0 || robots[robotIndex].column >= a)
        {
          cout<<"Robot "<<(robotIndex + 1)<<" crashes into the wall"<<'\n';
          return 0;
        }
        else if(map[robots[robotIndex].row][robots[robotIndex].column] != 0){ // 직진후 로봇과 부딪힘
          cout<<"Robot "<<(robotIndex + 1)<<" crashes into robot "<<map[robots[robotIndex].row][robots[robotIndex].column]<<'\n';
          return 0;
        }
        
        map[prevRow][prevColumn] = 0;
        map[robots[robotIndex].row][robots[robotIndex].column] = robotIndex + 1;
      }
    }
  }

  cout<<"OK"<<'\n';
}
