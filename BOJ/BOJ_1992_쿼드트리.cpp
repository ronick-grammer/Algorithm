//problem link: https://www.acmicpc.net/problem/1992
#include <iostream>
using namespace std;

int n;
int board[64][64];

void dfs(int size, int row, int column){
    
    int current = board[row][column]; 
    
    for(int i = row; i < row + size; i++) {
        for(int j = column; j < column + size; j++) {
            if(current != board[i][j]) { // 같은 숫자들이 한곳에 있는지 체크
                cout<<'(';
                dfs(size / 2, row, column); // 왼쪽 위
                dfs(size / 2, row, column + size / 2); // 오른쪽 위
                dfs(size / 2, row + size / 2, column); // 왼쪽 아래
                dfs(size / 2, row + size / 2, column + size / 2); // 오른쪽 아래
                cout<<')';

                return;
            }
        }
    }

    cout<<current;
}

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &board[i][j]);
        }
    }

    dfs(n, 0, 0);
}
