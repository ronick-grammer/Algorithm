// problem link: https://www.acmicpc.net/problem/1018

#include <iostream>
#include <algorithm>
using namespace std;

char w_board[8][8], b_board[8][8];
char board[50][50];
int n, m;

// 왼쪽 위가 흰색으로 시작하는 체스판, 그리고 검은색으로 시작하는 체스판을 만들기
void initBoard() {

    int count = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            if(i % 2 == 0) w_board[i][j] = (count % 2 == 0) ? 'B' : 'W';
            else w_board[i][j] = (count % 2 == 0) ? 'W' : 'B';

            if(i % 2 == 0) b_board[i][j] = (count % 2 == 0) ? 'W' : 'B';
            else b_board[i][j] = (count % 2 == 0) ? 'B' : 'W';

            count++;
        }
    }
}



int check(int row, int column) {

    int w_fixCount = 0;
    int b_fixCount = 0;

    for(int i = row; i < row + 8; i++) {
        for(int j = column; j < column + 8; j++) {
            // 흰색으로 시작하는 체스판으로 만들때 고쳐야하는 칸 수
            if(board[i][j] != w_board[i - row][j - column]) { 
                w_fixCount++;
            }
            // 검은색으로 시작하는 체스판으로 만들때 고쳐야 하는 칸 수
            if(board[i][j] != b_board[i - row][j - column]) {
                b_fixCount++;
            }
        }
    }
    
    // 고쳐야하는 칸 수가 더 적은걸 반환
    return min(w_fixCount, b_fixCount);
}

int main(void) {

    int minFix = 1e9;

    initBoard();

    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        scanf("%s", board[i]);
    }

    // 전체 보드에서 각 칸 전부를 돌면서 8x8 크기로 자르고 최소 fix 갯수 구하기
    for(int row = 0; row < m - 7; row++) {
        for(int column = 0; column < n - 7; column++) {
            minFix = min(minFix, check(row, column));
        }
    }

    cout<<minFix<<'\n';
}
