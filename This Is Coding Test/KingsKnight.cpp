#include <iostream>
using namespace std;

// 각 8가지 움직임에 따른 행, 열을 알맞게 초기화
int dr[8] = {-2, -2, 2, 2, -1, 1, -1, 1}; 
int dc[8] = {-1, 1, -1, 1, -2, -2, 2, 2}; 

int main(void){
    string startLocation; // 시작 위치
    int result = 0;

    cin>>startLocation;

    int column = (startLocation[0] - 'a') + 1; // 숫자 로 변환
    int row = startLocation[1] - '0'; 

    for(int i = 0; i < 8; i++){ // 총 8 가지의 움직임이 있으므로

        int nr = dr[i] + row;
        int nc = dc[i] + column;

        if(nr <= 0 || nr > 8 || nc <= 0 || nc > 8){ // 범위를 초과하면 무시
            continue;
        }
        else{
            result++; 
        }
    }

    cout<<result<<endl;
}
