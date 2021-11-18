//problem link: https://programmers.co.kr/learn/courses/30/lessons/77485
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int rotate(int ranges[4][4], vector<vector<int>> &board) {
    
    vector<vector<int> > temp_board = board;
    int minNum = 1e9;
    
    // 각 방향의 범위에 있는 숫자들을 한칸씩 옮기기
    for(int direction = 0; direction < 4; direction++) {
        
        for(int row = ranges[direction][0]; row <= ranges[direction][2]; row++) {
            for(int column = ranges[direction][1]; column <= ranges[direction][3]; column++) {
                int next_row = row + dr[direction];
                int next_column = column + dc[direction];
                board[next_row][next_column] = temp_board[row][column];

                minNum = min(minNum, temp_board[row][column]);
            }
        }
        
    }
    
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int> > board(rows + 1, vector<int> (columns + 1));
    int count = 1;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++){
            board[i][j] = count++;
        }    
    }
    
    for(int i = 0; i < queries.size(); i++) {
        // 시계방향 별로 각 범위를 지정하기
        int ranges[4][4] = {
            {queries[i][0], queries[i][1], queries[i][0], queries[i][3] - 1},
            {queries[i][0], queries[i][3], queries[i][2] - 1, queries[i][3]},
            {queries[i][2], queries[i][1] + 1, queries[i][2], queries[i][3]},
            {queries[i][0] + 1, queries[i][1], queries[i][2], queries[i][1]}
        };
        
        answer.push_back(rotate(ranges, board));
        
    }
        
    return answer;
}
