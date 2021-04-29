#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//problem link: https://www.acmicpc.net/problem/10836

int m, n;
int map[700][700];
int grow[1000001][3];

int main(void){
    cin >> m >> n;

    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &grow[i][0], &grow[i][1], &grow[i][2]); // 0, 1, 2 자라나는 정도
    }

    for(int i = 0; i < m; i++){
        fill_n(map[i], 700, 1);
    }

    for(int i = 1; i <= n; i++){
        int count = 1; // 0은 기본적으로 건너띔

        for(int j = grow[i][0]; j < m*2 - 1; j++){
            if(grow[i][count] == 0){
                count++;
            }

            if(j <= m - 1){ // 가장 왼쪽 아래에서 위로 
                map[m - j - 1][0] += count;
            }
            else{ // 가장 왼쪽 위에서 오른쪽으로
                map[0][j - m + 1] += count;
            }
            
            grow[i][count]--; // 자라나는 정도의 카운트를 하나씩 감소
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0){
                printf("%d ", map[i][j]); // 가장 왼쪽열과 가장 위쪽 행
            }
            else{
                printf("%d ", map[0][j]); // 그 외에는 해당 열의 가장 위쪽 행 애벌래의 크기를 가진다
            }
        }
        printf("\n");
    }
}
