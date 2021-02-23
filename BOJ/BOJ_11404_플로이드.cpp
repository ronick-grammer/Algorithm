#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

//problem link: https://www.acmicpc.net/problem/11404

int city[101][101];

int main(void){
    int n, m;
    
    cin>>n;
    cin>>m;

    for(int i = 1; i <= n; i++){
        fill_n(city[i], 101, INF); // 최소 비용으로 만들어줘야 하기 때문에 처음에는 가장 큰값으로 초기화
    }

    for(int from = 1; from <= 101; from++){
        for(int to = 1; to <= 101; to++){
            if(from == to){
                city[from][to] = 0; // 자기 자신한테 가는 간선은 0 으로 초기화
            }
        }
    }
    
    for(int i = 1; i <= m; i++){
        int A, B, cost;
        cin >> A >> B >> cost;
        
        // 간선이 하나가 아닐 경우 최소 비용을 넣어준다
        city[A][B] = min(city[A][B], cost);
    }

    // 플로이드 와샬 알고리즘 수행(도시의 최대 갯수(n)가 100이므로 O(n^3) 시간 복잡도로 수행할 수 있다)
    for(int through = 1; through <= n; through++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                city[from][to] = min(city[from][to], city[from][through] + city[through][to]); 
            }
        }
    }

    for(int from = 1; from <= n; from++){
        for(int to = 1; to <= n; to++){
            if(city[from][to] == INF){ // from 도시에서 to 도시로 가는 간선이 없는 경우 0 출력
                cout<<0<<' ';
            }
            else{
                cout<<city[from][to]<<' ';
            }
        }
        cout<<'\n';
    }
}
