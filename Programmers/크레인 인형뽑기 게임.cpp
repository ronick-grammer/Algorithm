#include <iostream>
#include <vector>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/64061

vector<int> container;

int checkContainer(vector<int>& check_container){
  int removed = true; // 처음에 제거할 것이라고 가정
  int removed_count = 0;

  while(removed){
    int post_doll = check_container[0];
    removed = false; // 인형을 제거했다면 true, 제거 못했다면 false
    for(int i = 1; i < check_container.size(); i++){
      int present_doll = check_container[i];
      // 아래부터 위로 두개의 인형이 같은지 확인한다
      if(post_doll == present_doll){
        check_container.erase(check_container.begin() + i);
        check_container.erase(check_container.begin() + (i - 1));
        removed_count += 2;
        removed = true;

        break;
      }

      post_doll = present_doll;
    }
  }

  return removed_count;
}

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    vector<vector<int> > newBoard(board.size());

    // 게임 형식이 마치 Last In Last Out 자료구조인 스택과 같으므로
    for(int i = 0; i < board.size(); i++){
      for(int j = board.size() - 1; j >= 0; j--){
        if(board[j][i] == 0){
          break;
        }
        newBoard[i].push_back(board[j][i]); // 맨 아래부터 차곡차곡 쌓는다
      }
    }
    
    for(int i = 0; i < moves.size(); i++){
      int number = moves[i] - 1; // 열 위치
      if(newBoard[number].size() > 0){ // 인형이 있다면

        // 크레인이 해당 번호의 열의 위에 있는 인형을 꺼내서
        int doll = newBoard[number].back();
        newBoard[number].pop_back();
        
        // 바구니에 담는다
        container.push_back(doll);
      }
    }

    answer = checkContainer(container);

    return answer;
}
