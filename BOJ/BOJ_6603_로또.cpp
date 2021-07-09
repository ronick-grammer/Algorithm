//problem link: https://www.acmicpc.net/problem/6603
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int s[12];

int main(void) {
    
    while(1){
        scanf("%d", &k);
        if(k == 0) break;

        for(int i = 0; i < k; i++) { 
            scanf(" %d", &s[i]);
        }

        vector<bool> visited(k, true);
        fill(visited.begin() + 6, visited.end(), false); // 복권은 여섯 숫자

        do {
            for(int i = 0; i < k; i++){
                if(visited[i])
                    printf("%d ", s[i]);
            }
            printf("\n");
            // 오름차순으로 정렬된 순열을 사전순으로 출력하려면 prev_permutation을 사용한다.
        } while(prev_permutation(visited.begin(), visited.end()));

        printf("\n");
    }
}
