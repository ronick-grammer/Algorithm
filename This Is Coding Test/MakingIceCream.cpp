#include <iostream>
using namespace std;

int n, m;
int result; // 만들 수 있는 아이스크림 갯수
int arr[1001][1001]; // 얼음 틀

int dfs(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= m){ // 범위 초과면 0 반환
        return 0;
    }

    if(arr[r][c] == 0){ // 방문한적  구멍이 뚫려있는 부분이라면 
        
        arr[r][c] = 1; // 방문 처리

        // dfs 진행
        dfs(r - 1, c);
        dfs(r + 1, c);
        dfs(r, c - 1);
        dfs(r, c + 1);

        return 1; // 1개의 아이스크림을 만들수 있음
        
    }
    else{ // 방문한 적이 있거나 벽이라면 0 반환
        return 0;
    }
}

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result += dfs(i, j); // 한 구멍씩 dfs 진행
        }
    }

    cout<<result<<endl;
}
