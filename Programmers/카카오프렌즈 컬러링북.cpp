//problem link: https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;

bool visited[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int row, int column, int m, int n, const vector<vector<int> > pic){
    queue<pair<int, int> > q;
    
    q.push(make_pair(row, column));
    visited[row][column] = true;
    int area = pic[row][column];
    int count = 1;
    while(!q.empty()){
        int current_row = q.front().first;
        int current_column = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4; i++){
            int next_row = current_row + dr[i];
            int next_column = current_column + dc[i];
            
            if(next_row < 0 || next_row >= m || next_column < 0 || next_column >= n)
                continue;

            if(!visited[next_row][next_column] && area == pic[next_row][next_column]){ // 같은 영역일 경우만 크기를 증가시킨다.
                visited[next_row][next_column] = true;
                count++;
                
                q.push(make_pair(next_row, next_column));
            }
        }
    }
    
    return count;
}

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    
    vector<int> answer(2);
    
    for(int i = 0; i < 100; i++){ // 우리 프로그래머스 성님께서 전역변수따위는 함수 내에서 초기화하란다. 프로그래머스에서는 프르그므스의 법을 따라야 한다. 
        fill(visited[i], visited[i] + 100, false);
    }
    
    int maxAreaSize = 0;
    int count_area = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && picture[i][j] != 0){ // 컬러 0은 영역으로 쳐주지 않는다
                maxAreaSize = max(maxAreaSize, bfs(i, j, m, n, picture));   
                count_area++;
            }
        }
    }
    
    answer[0] = count_area;
    answer[1] = maxAreaSize;

    return answer;
}
