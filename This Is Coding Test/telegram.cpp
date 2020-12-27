#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define INF 1e9

// 이 문제같은 경우 시작점에서 이어져 있는 '다른 도시들의 수'와 '최단 거리들 중 비용이 가장 큰 것'을 구하는 것으로
// 다익스트라 알고리즘으로 효과적으로 풀어 낼 수 있다.

int n, m, c; // n: 도시 갯수, m: 통로 갯수, c: 메시지를 보내고자 하는 도시
int count_city, time_max; // count_city: 메시지를 받는 도시의 총 갯수, time_max: 총 걸리는 시간

vector< pair<int, int> > graph[200000];
bool visited[30001];
int d[30001];
priority_queue< pair<int, int> > pQ;


void dijkstra(int start){ // 일반적인 다익스트라 알고리즘과 같다. 시작정점에서 모든정점으로 가는 모든 최소간선비용을 구한다
    d[start] = 0;
    pQ.push(make_pair(0, start));

    while(!pQ.empty()){
        int index_min = pQ.top().second;
        visited[index_min] = true;
        pQ.pop();
        
        for(int i = 0; i < graph[index_min].size(); i++){
            int nextIndex = graph[index_min][i].first;
            int nextCost = d[index_min] + graph[index_min][i].second;
            if(!visited[nextIndex]){
                if(d[nextIndex] > nextCost){
                    pQ.push(make_pair(-nextCost, nextIndex)); // c++ 의 우선순위 큐는 최대값을 루트로 두고 있으므로 -를 붙여준다
                    d[nextIndex] = nextCost;
                }
            }
        }
    }
}

int main(void){
    cin >> n >> m >> c;

    for(int i = 0; i < m; i++){
        int x, y, z; // 도시 x 에서 도시 y 로 가는 z 비용
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
    }
    
    fill_n(d, 30001, INF);
    dijkstra(c);

    for(int i = 1; i <= n; i++){  // 도시 수만큼 진행
        if(d[i] != INF){ // INF 라면 시작 도시에서 다른 도시로 가는 간선이 없는 경우
            time_max = max(time_max, d[i]); 
            count_city++;
        }
    }
    // 시작노드는 카운트에서 제외
    cout<<count_city - 1 <<' '<<time_max<<endl;
}
