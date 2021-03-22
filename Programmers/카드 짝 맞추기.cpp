#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1e9

//problem link: https://programmers.co.kr/learn/courses/30/lessons/72415

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

class SameCards{
public:
  pair<int, int> a_card;
  pair<int, int> b_card;
  int cardNumber;

  SameCards(pair<int, int> a_card, pair<int, int> b_card, int cardNumber){
    this->a_card = a_card;
    this->b_card = b_card;
    this->cardNumber = cardNumber;
  }
};

// 카드 번호 기준으로 오름차순 정렬
bool compare(SameCards a, SameCards b){
  return a.cardNumber < b.cardNumber;
}

// 보드 범위 체크
bool checkRange(int row, int column){
  if(row < 0 || row > 3 || column < 0 || column > 3){
    return false;
  }
  return true;
}
//CTRL + 방향키 일때 방향에 따라 보드의 끝인지 확인하기
bool check_endOfBoard_withDirection(int row, int column, int direction){
  // direction up: 0, direction down: 1, direction left: 2, direction right: 3
  if((row == 0 && direction == 0) || (row == 3 && direction == 1)
    || (column == 0 && direction == 2) || (column == 3 && direction == 3)){
      return true;
  }
  return false;
}

// 동일한 카드 a와 b의 위치들을 담고 반환
vector<SameCards> getSameCardLocation(const vector<vector<int> > &v){
  vector<SameCards> sameCards;
  vector< pair<int, pair<int, int> > >cards;

  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v.size(); j++){
      
      if(v[i][j] != 0){
        cards.push_back(make_pair(v[i][j], make_pair(i, j)));
      }
    }
  }
  
  vector<bool> visited(cards.size(), false);
  for(int i = 0; i < cards.size(); i++){
    if(visited[i]) continue;
    int cardNumber = cards[i].first;
    for(int j = i + 1; j < cards.size(); j++){
      if(cardNumber == cards[j].first){
        sameCards.push_back(SameCards(cards[i].second, cards[j].second, cardNumber));
        visited[i] = true;
        visited[j] = true;
      }
    }
  }
  
  return sameCards;
}

bool condition = false;
// 특정 카드 위치에서 다른 모든 위치들로 가는 최소 조작 횟수를 담은 보드 반환
vector<vector<int> >  bfs(int startRow, int startColumn, const vector<vector<int> > &board){
  queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(0, make_pair(startRow, startColumn)));

  // 조작횟수 비용을 담을 변수
  vector<vector<int> > board_cost(4, vector<int>(4, INF));
  board_cost[startRow][startColumn] = 0; // 시작 커서 위치->시작 커서 위치, 최소 조작횟수: 0
  while(!q.empty()){
    int current_row = q.front().second.first;
    int current_column = q.front().second.second;
    int current_cost = q.front().first;
    
    q.pop();
    
    for(int i = 0; i < 4; i++){
      // 상 하 좌 우 1칸 전진
      int next_row = current_row + dr[i];
      int next_column = current_column + dc[i];
      int next_cost = current_cost + 1;

      if(!checkRange(next_row, next_column)){
        continue;
      }
      
      if(next_cost < board_cost[next_row][next_column]){
        board_cost[next_row][next_column] = next_cost;
        q.push(make_pair(next_cost, make_pair(next_row, next_column)));
      }

      // CTRL + 방향키
      int next_CTRL_row = current_row;
      int next_CTRL_column = current_column;
      
      for(int j = 0; j < 3; j++){ // j 가 3 까지인 이유: 끝점에서 끝점까지 가는 최대 칸수가 3이기 때문에
        next_CTRL_row += dr[i];
        next_CTRL_column += dc[i];

        // 가장 가까운 카드이거나 보드 끝이면
        if(check_endOfBoard_withDirection(next_CTRL_row, next_CTRL_column, i)|| board[next_CTRL_row][next_CTRL_column] != 0 ){
          // 최소 조작횟수 저장
          if(next_cost < board_cost[next_CTRL_row][next_CTRL_column]){
            board_cost[next_CTRL_row][next_CTRL_column] = next_cost;
            q.push(make_pair(next_cost, make_pair(next_CTRL_row, next_CTRL_column)));
          }
          break;
        }
      }
    }
  }
  return board_cost;
}

// 현재 커서 위치에서 동일한 두개의 카드의 위치에서 각각 출발하는 경우를 고려
int dfs(pair<int, int> cursor, int cardIndex, vector<SameCards> sameCards, vector<vector<int> > board){
  
  if(cardIndex >= sameCards.size()){
    return 0;
  }

  //같은 카드 Xa 와 Xb 의 위치 받기
  pair<int, int> current_card_Xa = sameCards[cardIndex].a_card;
  pair<int, int> current_card_Xb = sameCards[cardIndex].b_card;

  //현재 커서 위치에서 Xa 위치와 Xb 로 가는 최소 조작 횟수 구하기
  vector<vector<int> > costBoard_fromCursor = bfs(cursor.first, cursor.second, board);
  int cost_fromCursor_toXa = costBoard_fromCursor[current_card_Xa.first][current_card_Xa.second];
  int cost_fromCursor_toXb = costBoard_fromCursor[current_card_Xb.first][current_card_Xb.second];
  
  // Xa 에서 Xb로 가는 최소 조작 횟수 구하기
  vector<vector<int> > costBoard_fromXa = bfs(current_card_Xa.first, current_card_Xa.second, board);
  int cost_fromXa_toXb = costBoard_fromXa[current_card_Xb.first][current_card_Xb.second];
  
  // Xb 에서 Xa로 가는 최소 조작 횟수 구하기
  vector<vector<int> > costBoard_fromXb = bfs(current_card_Xb.first, current_card_Xb.second, board);
  int cost_fromXb_toXa = costBoard_fromXb[current_card_Xa.first][current_card_Xa.second];

  // 동일한 두 카드를 골랐으므로 없애주기
  board[current_card_Xa.first][current_card_Xa.second] = 0;
  board[current_card_Xb.first][current_card_Xb.second] = 0;

  // cursor 위치 -> Xa -> Xb 로 가는 최소 조작 횟수
  int minCost_fromXa_toXb = (cost_fromCursor_toXa + cost_fromXa_toXb) + dfs(current_card_Xb, cardIndex + 1, sameCards, board);
  // cursor 위치 -> Xb -> Xa 로 가는 최소 조작 횟수
  int minCost_fromXb_toXa = (cost_fromCursor_toXb + cost_fromXb_toXa) + dfs(current_card_Xa, cardIndex + 1, sameCards, board);
  
  // 엔터 두번
  return min(minCost_fromXa_toXb + 2, minCost_fromXb_toXa + 2);
}

int solution(vector<vector<int> > board, int r, int c) {
  int answer = 0;
  // 동일한 카드 a와 b의 위치를 저장
  vector<SameCards> sameCards = getSameCardLocation(board);

  // permutation 함수를 사용하기 위해 정렬
  sort(sameCards.begin(), sameCards.end(), compare);
  
  int minCost = INF;
  do{

    vector<vector<int> > temp_board = board;
    minCost = min(minCost, dfs(make_pair(r, c), 0, sameCards, temp_board));

  }while(next_permutation(sameCards.begin(), sameCards.end(), compare));

  answer = minCost;

  return answer;
}
