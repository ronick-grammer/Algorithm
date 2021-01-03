#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[100][100]; 

int main(void){
    cin >> n >> m;
    int max_num = 0; 

    for(int i = 0; i < n; i++){ // 행과 열에 따라 카드 번호 입력
        for(int j = 0; j < m; j++){
            cin >> cards[i][j]; 
        }
        sort(cards[i], cards[i] + m); // 행별로 가장 작은 수를 얻기 위해 정렬
        max_num = max(max_num, cards[i][0]); // 행별로 가장 작은 수들중 가장 큰 수를 얻는다
    }
    
    
    cout<<max_num<<endl; // 짜잔
}
