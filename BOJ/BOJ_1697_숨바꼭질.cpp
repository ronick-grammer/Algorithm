#include <iostream>
#include <queue>
using namespace std;

// problem link: https://www.acmicpc.net/problem/1697

int n, k, visited[100001];

void bfs(){
  queue<int> q;
  q.push(n);
  visited[n] = 0;

  while(!q.empty()){
    int current = q.front();
    q.pop();
    
    if(current == k) break; // 찾으면 종료

    // 뒤로 갔을 때 범위를 초과 하지 않으면서 한번도 간적이 없으면 
    if(current - 1 >= 0 && visited[current - 1] == 0){ 
      visited[current - 1] = visited[current] + 1; // 뒤로 움직여서 업데이트 된 횟수 = 현재까지 움직인 횟수 + 1
      q.push(current - 1);
    }
    // 앞으로 갔을 때 범위를 초과 하지 않으면서 한번도 간적이 없으면
    if(current + 1 <= 100000 && visited[current + 1] == 0){ // 앞으로 움직여서 업데이트 된 횟수 = 현재까지 움직인 횟수 + 1
      visited[current + 1] = visited[current] + 1;
      q.push(current + 1);
    }
    // 텔레포트 했을 때 범위를 초과 하지 않으면서 한번도 간적이 없으면
    if(current * 2 <= 100000 && visited[current * 2] == 0){ // 텔레포트 해서 업데이트된 횟수 = 현재까지 움직인 횟수 + 1
      visited[current * 2] = visited[current] + 1;
      q.push(current * 2);
    }
  }
}

int main(void){
  cin >> n >> k;

  bfs();

  cout<<visited[k]<<'\n';
}
