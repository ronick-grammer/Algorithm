#include <iostream>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1043

// 전형적인 집합(union) 문제이다. 처음에는 진실을 0 으로 두고 진실을 아는 파티 참가자들은 0을 가르키게 한다.
// 그 후 모든 각 파티의 참가자들을 서로 union 시키면 해당 파티에 진실(== 0)을 아는(가르키는) 참가자가 있을 경우
// 기존에 진실을 모르던 사람도 진실(== 0)을 알게(가르키게) 된다. 마지막으로 모든 각 파티의 참가자들이 진실(== 0)을
// 아는지(가르키는지) 혹은 진실을 아는 사람을 가르키는지 확인해주면 된다. 


int n, m;
int parent[51];

vector<int> whoKnows;
vector<int> participant_eachParty[51];
int result;

int findParent(int x){
  if(parent[x] == x){
    return x;
  }
  else{
    return parent[x] = findParent(parent[x]);
  }
}

void unionParent(int a, int b){
  int parent_a = findParent(a);
  int parent_b = findParent(b);

  if(parent_a < parent_b){
    parent[parent_b] = parent_a;
  }
  else{
    parent[parent_a] = parent_b;
  }
}

int getResult(){
  for(int i = 1; i <= m; i++){
    // 우선 각 파티의 사람들을 모두 유니온 해준다.
    for(int j = 1; j < participant_eachParty[i].size(); j++){ 
        int a = participant_eachParty[i][j - 1];
        int b = participant_eachParty[i][j];
        unionParent(a, b);
    }
  }

  for(int i = 1; i <= m; i++){ // 갈 수 없는 파티 갯수를 카운트 해준다
    for(int j = 0; j < participant_eachParty[i].size(); j++){
      int x = participant_eachParty[i][j];
      if(findParent(x) == 0){ // 각 파티의 참가자들이 진실을 알고 있으면
        result++; // 그 파티는 갈 수 없다
        break;
      }
    }
  }

  return m - result; // 갈 수 있는 최대 파티 수
}

int main(void){
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++){
    parent[i] = i; // 처음에는 자기 자신으로 초기화
  }

  int size_whoKnows;
  cin >> size_whoKnows;
  for(int i = 0; i < size_whoKnows; i++){
    int x;
    cin >> x;
    whoKnows.push_back(x);
  }

  for(int i = 0; i < whoKnows.size(); i++){
    parent[whoKnows[i]] = 0; // 사람들은 진실(== 0)을 알고 있다
  }

  for(int i = 1; i <= m; i++){
    int size_participant;
    cin >> size_participant;

    for(int j = 0; j < size_participant; j++){
      int x;
      cin >> x;
      
      participant_eachParty[i].push_back(x);
    }
  }

  cout<<getResult()<<'\n';
}
