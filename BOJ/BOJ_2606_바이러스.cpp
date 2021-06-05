//problem link: https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, connect_size;
vector<int> computers[101];
bool visited[101];

int bfs(int start){
    queue<int> q;
    q.push(start);

    visited[start] = true;
    int count = 0;

    while(!q.empty()){
        int current_computer = q.front();
        q.pop();

        for(int i = 0; i < computers[current_computer].size(); i++){
            int next_computer = computers[current_computer][i];

            if(visited[next_computer]) continue; // 이미 감염된거면 패스

            visited[next_computer] = true; // 감염시키기
            q.push(next_computer); // 감염된 컴퓨터와 연결된 컴퓨터를 찾기 위해 푸시
            count++;
        }
    }

    return count;
}

int main(void){
    cin >> n;
    cin >> connect_size;

    for(int i = 0; i < connect_size; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        computers[a].push_back(b);
        computers[b].push_back(a);
    }

    cout<<bfs(1)<<'\n';
}
