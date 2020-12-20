#include <iostream>
using namespace std;

int n_notSorted = 15;
int arr[15] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};

int n_sorted = 10;
int sorted[10];


int main(void){
    for(int i = 0; i < n_notSorted; i++){
        sorted[arr[i]]++; //데이터의 등장횟수를 데이터와 동일한 인덱스에 저장
    }

    for(int i = 0; i < n_sorted; i++){
        for(int j = 0; j < sorted[i]; j++){ // 데이터의 등장횟수 만큼 데이터 출력
            cout<<i<<" ";
        }
    }
}
