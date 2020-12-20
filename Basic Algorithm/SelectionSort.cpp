#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int array[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8}; 
    
    for(int i = 0; i < 10; i++){
        int min_index = i; //최소값 인덱스
        for(int j = i+1; j < 10; j++){ 
            if(array[j] < array[min_index]){ //하나하나씩 비교하여 최소값 인덱스 재설정
                min_index = j;
            }
        }
        swap(array[i], array[min_index]); // 스왑
    }

    for(int i = 0; i < 10; i++){
        cout<<array[i]<<" ";
    }
}
