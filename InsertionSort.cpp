#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n = 10;
    int array[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};


    for(int i = 0; i < n - 1; i++){
        int min_index = i + 1; //1부터 시작
        for(int j = min_index; j > 0; j--){ // 비교할 값 하나씩 감소
            if(array[min_index] < array[j-1]){ // 작으면 계속 스왑
                swap(array[j-1], array[min_index]);
                min_index = j-1; // 인덱스 재설정
            }
            else{ // 크면 그자리에서 멈춤
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
}
