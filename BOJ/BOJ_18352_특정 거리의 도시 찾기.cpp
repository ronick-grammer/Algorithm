#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18352

int n, m, k, x;
vector<int> v[300001];
vector<int> result;
int visited[300001];

void bfs(int start){
    queue<int> q;

    q.push(start);
    visited[start] = 0;

    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int i = 0; i < v[from].size(); i++){
            int to = v[from][i];
            
            if(visited[to] == -1){ // 방문한 적이 없으면
                visited[to] = visited[from] + 1; // 최단 거리를 구해준다
                
                if(visited[to] == k){
                    result.push_back(to);
                }
                q.push(to);
            }
        }
    }
}

int main(void){
    cin >> n >> m >> k >> x;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        
        v[from].push_back(to);
    }

    fill_n(visited, 300001, -1);
    bfs(x);

    if(result.size() == 0){ // 최단거리인 정점이 하나도 없으면
        cout<<-1<<endl;
    }
    else{
        sort(result.begin(), result.end()); 

        for(int i = 0; i < result.size(); i++){
            cout<<result[i]<<endl;
        }
    }
}
