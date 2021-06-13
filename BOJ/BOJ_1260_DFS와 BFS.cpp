//problem link: https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, startV;

vector<int> v[1001];
bool visited[1001];

void dfs(int x){
    cout<<x<<' ';
    visited[x] = true;
    
    for(int i = 0; i < v[x].size(); i++){
        int next = v[x][i];
        if(!visited[next])
            dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        
        for(int i = 0; i < v[x].size(); i++){
            int next = v[x][i];
            
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void){
    cin >> n >> m >> startV;

    for(int i = 0; i < m; i++){
        int a, b;
        scanf(" %d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){ // 정점 번호가 작은 것을 먼저 방문하도록 하기 위해서 정렬
        sort(v[i].begin(), v[i].end());
    }

    dfs(startV);
    cout<<'\n';

    fill_n(visited, 1001, false);
    bfs(startV);
}
