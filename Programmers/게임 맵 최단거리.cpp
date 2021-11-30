//problem link: https://programmers.co.kr/learn/courses/30/lessons/1844
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int bfs(int startRow, int startColumn, vector<vector<int> > maps) {
    queue<pair<int, pair<int, int> > > q;
    vector<vector<int> > distance_map(maps.size(), vector<int> (maps[0].size(), 1e9));
    
    // 첫 칸 갯수
    distance_map[startRow][startColumn] = 1;
    
    q.push(make_pair(1, make_pair(startRow, startColumn)));
    while(!q.empty()) {
        int current_row = q.front().second.first;
        int current_column = q.front().second.second;
        int current_distance = q.front().first;
        
        q.pop();
        
        for(int i = 0 ; i < 4; i++) {
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            int next_distance = current_distance + 1;
            
            if(next_row < 0 || next_row >= maps.size() || next_column < 0 || next_column >= maps[0].size() || maps[next_row][next_column] == 0) 
                continue;
            
            if(next_distance < distance_map[next_row][next_column]) {
                q.push(make_pair(next_distance, make_pair(next_row, next_column)));
                distance_map[next_row][next_column] = next_distance;
            }
        }
    }
    
    int endRow = maps.size() - 1;
    int endColumn = maps[0].size() - 1;
    
    // 도착할 수 없으면 -1,
    return (distance_map[endRow][endColumn] == 1e9) ? -1 : distance_map[endRow][endColumn];
    
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    return bfs(0, 0, maps);
}
