#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
#define INF 1e9

//problem link: https://www.acmicpc.net/contest/problem/603/4

int graph[101][101];
int minCosts[101];

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  int a_small, a_big, b_small, b_big;
  if(a.second.first < a.second.second){
    a_small = a.second.first;
    a_big = a.second.second;
  } 
  else{
    a_big = a.second.first;
    a_small = a.second.second;
  }
  
  if(b.second.first < b.second.second){
    b_small = b.second.first;
    b_big = b.second.second;
  } 
  else{
    b_big = b.second.first;
    b_small = b.second.second;
  }
  
  if(a.first == b.first){
    if(a_small == b_small){
      return a_big < b_big;
    }
    else{
      return a_small < b_small;
    }
  }
  else{
    return a.first < b.first;
  }
}

int main(void){
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= 101; i++){
    fill_n(graph[i], 101, INF);
  }
  for(int i = 1; i <= 101; i++){
    graph[i][i] = 0; // 자기자신 -> 자기자신은 0
  }
  
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  // 각 모든 지점에서 다른 모든 지점까지의 최소 비용을 구함
  for(int through = 1; through <= n; through++){
    for(int from = 1; from <= n; from++){
      for(int to = 1; to <= n; to++){
        graph[from][to] = min(graph[from][to], graph[from][through] + graph[through][to]);
      }
    }
  }

  
  vector<bool> visited(n, false);
  fill(visited.end() - 2, visited.end(), true); 
  int minCost = INF;
  vector<pair<int, pair<int, int> > > twoChicken;
  // 두개의 건물 조합을 모두 따져서 적절한 치킨 집 건물 두개를 정한다
  do{
    fill_n(minCosts, 101, INF);

    int count = 0;
    int chickenhouse[2]; // 적절한 치킨 집 두개를 찾기위한 건물 두개를 선정
    for(int i = 0; i < visited.size(); i++){
      if(visited[i]){ // 각 건물 j 에서 두 예비 치킨집(i+1)으로 가는 최소 거리중 더 짧은 걸 정함
        for(int j = 1; j <= n; j++){
          minCosts[j] = min(minCosts[j], graph[j][i + 1]); 
        }
        chickenhouse[count] = i + 1; // 특정 건물 번호(예비 치킨집)
        count++;
      }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++){ // 그 비용의 총합을 구한다.
      sum += minCosts[i];
    }
    // 두개의 예비 치킨집 번호와 각 건물에서 더 가까운 예비 치킨집으로 가는 최소 거리 비용의 합을 삽입
    twoChicken.push_back(make_pair(sum, make_pair(chickenhouse[0], chickenhouse[1]))); 

  }while(next_permutation(visited.begin(), visited.end()));

  // 조건에 맞게 정렬
  sort(twoChicken.begin(), twoChicken.end(), compare);

  cout<<twoChicken[0].second.first<<' '<<twoChicken[0].second.second<<' '<<twoChicken[0].first * 2<<'\n';
}
