#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

// 5개의 대기실에서 대기자들이 거리두기를 잘 지켰는지 확인하기
// 1. 대기자('P')와 대기자 한칸 사이에 칸막('X')이 있으면 거리두기 지킴
// 2. 대기자('P')의 한칸 대각선 위치에 에 대기자가 있지만 그 반대 대각선의 위치 두곳에 칸막('X')이 있으면 거리두기 지킴
// 3. 위의 조건을 만족하지 않음과 동시에 |Px1 - Px2| + |Py1 -  Py2| 거리가 2 이하이면 거리두기 지키지 않은 것
// 4. 다만 2 이상이면 거리두기를 지킴
// 'O'는 빈칸을 의미
// 이렇게 각 대기실에서 거리두기를 지켰으면 1 아니면 0 을 표시해서 벡터로 반환
vector<pair<int, int> > waitingRoom[5];
bool visited[5][5];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool bfs(int startRow, int startColumn, vector<string> s){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(startRow, startColumn)));
    visited[startRow][startColumn] = true;
    
    while(!q.empty()){
        int current_row = q.front().second.first;
        int current_column = q.front().second.second;
        int current_cost = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            int next_cost = current_cost + 1;

            if(next_row < 0 || next_row >= 5 || next_column < 0 || next_column >= 5)
                continue;

            if(!visited[next_row][next_column] && s[next_row][next_column] != 'X'){
                if(s[next_row][next_column] == 'P'){
                    if(next_cost <= 2) 
                        return false;
                }
                q.push(make_pair(next_cost, make_pair(next_row, next_column)));
                visited[next_row][next_column] = true;
            }
        }
    }

    return true;
}

void initVisited(){
    for(int i = 0; i < 5; i++){
        fill_n(visited[i], 5, false);
    }
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(places[i][j][k] == 'P')
                    waitingRoom[i].push_back(make_pair(j, k));
            }
        }
    }
    
    for(int i = 0; i < 5; i++){
        bool validate = true;
        for(int j = 0; j < waitingRoom[i].size(); j++){
            if(!bfs(waitingRoom[i][j].first, waitingRoom[i][j].second, places[i])){
                validate = false;
            }
            initVisited();
        }
        if(validate) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}


// 테스트 케이스
int main(void){
    vector<string> s1;
    s1.push_back("POOOP");
    s1.push_back("OXXOX");
    s1.push_back("OPXPX");
    s1.push_back("OOXOX");
    s1.push_back("POXXP");
    vector<string> s2;
    s2.push_back("POOPX");
    s2.push_back("OXPXP");
    s2.push_back("PXXXO");
    s2.push_back("OXXXO");
    s2.push_back("OOOPP");
    vector<string> s3;
    s3.push_back("PXOPX");
    s3.push_back("OXOXP");
    s3.push_back("OXPXX");
    s3.push_back("OXXXP");
    s3.push_back("POOXX");
    vector<string> s4;
    s4.push_back("OOOXX");
    s4.push_back("XOOOX");
    s4.push_back("OOOXX");
    s4.push_back("OXOOX");
    s4.push_back("OOOOO");
    vector<string> s5;
    s5.push_back("PXPXP");
    s5.push_back("XPXPX");
    s5.push_back("PXPXP");
    s5.push_back("XPXPX");
    s5.push_back("PXPXP");
    vector<vector<string> > s;
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    s.push_back(s4);
    s.push_back(s5);
    vector<int> result = solution(s);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<'\n';
    
}
