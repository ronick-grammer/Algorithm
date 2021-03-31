#include <iostream>
#include <queue>
using namespace std;

int main(void){
  int n;
  queue<int> q;

  cin >> n;
  for(int i = 1; i <= n; i++){
    q.push(i);
  }

  while(q.size() > 1){ // 하나 남을 때까지 진행
    q.pop(); // 맨 위에 있는 카드 제거
    
    // 그 다음에 맨 위에 있는 카드를 맨 밑으로 보냄
    q.push(q.front()); 
    q.pop();
  }

  cout<<q.front()<<'\n';
}
