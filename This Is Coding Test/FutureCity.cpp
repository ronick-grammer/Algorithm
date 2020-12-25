#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int n, m, x, k; // n: 정점 갯수, m: 간선 갯수, x: 목표정점, k: 거쳐가는 정점
int graph[101][101];

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        fill_n(graph[i], 101, INF); // 모든 정점을 무한대로 우선 초기화, 
    }

    for(int i = 1; i <= 100; i++){ // 자기자신에서 자기자신으로 가는 간선 비용은 0
        for(int j = 1; j <= 100; j++){
            if(i == j) graph[i][j] = 0; 
        }
    }

    for(int i = 0; i < m; i++){ // 정점에서 정점은 양방향으로 이동가능
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    cin >> m >> k;
    
    for(int through = 1; through <= n; through++){ // through : 거쳐가는 정점
        for(int from = 1; from <= n; from++){ // from: 시작 정점
            for(int to = 1; to <= n; to++){ // to : 도착 정점
                // Floyd Warshall 진행
                graph[from][to] = min(graph[from][to], graph[from][through] + graph[through][to]); 
            }
        }
    }    

    int result = graph[1][k] + graph[k][m]; // 시작 정점점점 -> 거쳐가는 정점 -> 도착할 정점 
    if(result == INF){ // 경로가 없으면 -1 출력
        cout<<-1<<endl;
    }
    else{
        cout<<result<<endl;
    }
}
