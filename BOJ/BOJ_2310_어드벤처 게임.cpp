#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/2310

class RoomInfo{

public:
  char type;
  int cost;
  vector<int> roomNumber;

  RoomInfo(char type, int cost, vector<int> roomNumber){
    this->type = type;
    this->cost = cost;
    this->roomNumber = roomNumber;
  }
};

vector<int> rooms;
vector<RoomInfo> roomInfo;
int n;
bool visited[1001];
bool success;

void dfs(int roomNumber, int currentCost){
  char type = roomInfo[roomNumber].type;
  int roomCost = roomInfo[roomNumber].cost;

  if(type == 'L'){
    if(currentCost < roomCost)
      currentCost = roomCost;
  }

  if(type == 'T'){

     if(currentCost < roomCost){
       return;
     }
     else{
       currentCost -= roomCost;
     }
  }

  if(roomNumber == n - 1){
    success = true;
    return;
  }

  visited[roomNumber] = true; 
  for(int i = 0; i < roomInfo[roomNumber].roomNumber.size(); i++){
    int nextRoomNumber = roomInfo[roomNumber].roomNumber[i];

    if(!visited[nextRoomNumber])
      dfs(nextRoomNumber, currentCost); // 다음 방 방문
  }
  visited[roomNumber] = false; // 다른 방이 방문하는 다른 경우를 위해 초기화
}

int main(void){
  while(1){
    cin >> n;
    
    if(n == 0){
      break;
    }
    
    for(int i = 0; i < n; i++){
      char type;
      int cost;
      cin >> type;
      cin >> cost;

      int x;
      while(1){
        cin >> x;
        if(x == 0) break;

        rooms.push_back(x - 1); // 방 번호는 0 부터 시작
      }

      roomInfo.push_back(RoomInfo(type, cost, rooms));
      rooms.clear();
    }

    success = false;
    
    dfs(0, 0);
    if(success){
      cout<<"Yes"<<'\n';
    }
    else{
      cout<<"No"<<'\n';
    }

    roomInfo.clear();
  }
}
