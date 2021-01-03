#include <iostream>
#include <string>
using namespace std;

int dc[4] = {-1, 1, 0, 0}; // 좌, 우
int dr[4] = {0, 0, -1, 1}; // 위, 아래
char direction[4] = {'L', 'R', 'U', 'D'}; // 좌, 우, 위, 아래
string movement; 
int row = 1, column = 1; // 현재 위치

int main(void){
    int n;
    cin>>n;
    cin.ignore(); // 버퍼 비우기
    getline(cin, movement); // 공백을 포함하여 입력
    

    for(int i = 0; i < movement.size(); i++){
        
        int nr = 0 , nc = 0; // 움직인 후의 좌표
        for(int j = 0; j < 4; j++){
            if(movement[i] == direction[j]){ // 좌, 우, 위, 아래 에 대하여 연산 수행
                
                nr = row + dr[j]; 
                nc = column + dc[j];
                break;
            }
        }

        if(nr <= 0 || nr > n || nc <= 0 || nc > n){ // 범위를 초과하면 건너띈다.
            continue;
        }
        
        row = nr; // 현재 좌표를 다시 설정
        column = nc;
    }

    cout<<row<<' '<<column<<endl;
}
