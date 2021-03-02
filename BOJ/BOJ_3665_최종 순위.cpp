#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/3665

int inDegree[501]; // 진입차수
bool graph[501][501]; // 순위가 높은 팀은 자기보다 낮은 팀을 가르킨다

int main(void){
    int testCase;
    cin>>testCase;

    for(int tc = 0 ; tc < testCase; tc++){
        vector<int> teamRanking;

        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            int teamNumber;
            cin >> teamNumber;
            
            teamRanking.push_back(teamNumber); // 작년 랭킹 
        }
        
        fill_n(inDegree, 501, 0); // 진입차수와, 진입 그래프 초기화
        for(int i = 0; i < 501; i++){
            fill_n(graph[i], 501, false);
        }

        for(int i = 0; i < n; i++){
            int teamNumber = teamRanking[i];

            for(int j = i + 1; j < n; j++){
                graph[teamNumber][teamRanking[j]] = true; // 순위가 높은 팀은 자기보다 낮은 팀을 가르킨다
                inDegree[teamRanking[j]]++; // 진입차수
            }
        }

        int m;
        cin>>m;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            
            if(graph[a][b]){ // a 가 b 를 가르켰다면, b가 a를 가르키게 한다
                inDegree[a]++;
                inDegree[b]--;

                graph[a][b] = false;
                graph[b][a] = true;
            }
            else{ // 반면 b 가 a 를 가르켰다면, a가 b를 가르키게 한다
                inDegree[b]++;
                inDegree[a]--;

                graph[b][a] = false;
                graph[a][b] = true;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(inDegree[i] == 0){ // 어떤 팀의 진입차수가 0이라면 그 팀이 1위라는 뜻이다
                q.push(i);
            }
        }

        vector<int> result; // 순위 결과
        bool cycle = false; // 사이클이 여부("IMPOSSIBLE" 여부)
        bool unCertain = false; // 확실한 순위 여부("?" 여부)
        for(int i = 0; i < n; i++){
            if(q.empty()){ // 순위가 모두 결정되기도 전에 사이클이 생겼다면
                cycle = true;
                break;
            }
            else if(q.size() >= 2){ // 순위가 결정되기도 전에 두개의 팀이 중복 순위라면
                unCertain = true;
                break;
            }
 
            int teamNumber = q.front(); 
            q.pop();

            result.push_back(teamNumber); // 현재 팀의 순위를 차례대로 저장

            for(int j = 1; j <= n; j++){  
                if(graph[teamNumber][j]){ // 현재 팀이 가르키는 팀의 진입차수를 빼준다
                    inDegree[j]--;
                    
                    if(inDegree[j] == 0){ // 그리고 그 가리키는 팀의 진입차수가 0이라면 그 팀이 다음 순위이다.
                        q.push(j);
                    }
                }
            }
        }

        if(cycle){
            cout<<"IMPOSSIBLE"<<'\n';
        }
        else if(unCertain){
            cout<<"? \n";
        }
        else{
            for(int i = 0; i < result.size(); i++){
                cout<<result[i]<<' ';
            }
            cout<<'\n';
        }
    }
}
