#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int graph[501][501]; // 각 정점들까지의 최단 거리를 담을 변수
int n, m; // n : 정점의 갯수, m : 간선의 갯수

int main(void){
    cin >> n >> m;

    for(int i = 0; i < 501; i++){ // 전부 무한으로 초기화
        fill_n(graph[i], 501, INF);
    }

    for(int i = 1; i <= n; i++){ // 자기 자신에서 자기 자신으로 가는 간선 정보 0 으로 초기화
        for(int j = 1; j <= n; j++){
            if(i == j){
                graph[i][j] = 0;
            }
        } 
    }

    for(int i = 0; i < m; i++){ // 정점 -> 정점에 드는 간선 비용 입력
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
    }

    for(int through = 1; through <= n; through++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                graph[from][to]= min(graph[from][to], graph[from][through] + graph[through][to]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
}
