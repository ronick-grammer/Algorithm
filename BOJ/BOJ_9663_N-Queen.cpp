//problem link: https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;
// dp 문제인줄 알았는데 백트래킹 문제였다. dp 보다 dfs로 백트래킹하는 문제가 나한테는 까다롭다.
int n;
int col[15];
int result;

bool validate(int row){
    for(int i = 0; i < row; i++){
        // 같은 열에 존재 하거나, 대각선에 위치하면 false(행의 차이와 열의 차이가 동일하다면 대각선에 위치한다는 것이다)
        if(col[i] == col[row] || abs(col[row] - col[i]) == row - i) 
            return false;
    }

    return true;
}

void dfs(int row) {
    if(row == n){
        result++;
        return;
    }

    for(int i = 0 ; i < n; i++){
        // col[row] = i : row 행 i 열 위치에 퀸 놓음
        col[row] = i;
        
        if(validate(row)) // 놓을 수 있는지 확인하기
            dfs(row + 1); // 놓을 수 있으면 다음 행에 놓기 위해 이동
    }
}

int main(void){
    cin>>n;

    dfs(0);
    cout<<result<<'\n';
}
