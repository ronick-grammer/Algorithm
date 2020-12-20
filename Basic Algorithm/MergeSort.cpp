#include <iostream>
using namespace std;

int n = 10; // 숫자의 갯수
int merged[10]; // 병합될 임시 전역 변수

void merge(int *arr, int leftStart, int middle, int rightEnd){
    int index_left = leftStart; // 분할된 왼쪽 그룹 인덱스
    int index_right = middle + 1; // 분할된 오른쪽 그룹 인덱스
    int index_merged = leftStart;  // 병합될 그룹 인덱스

    while(index_left <= middle && index_right <= rightEnd){ // 분할된 두 그룹중 한 그룹이라도 전부 병합 변수로 옮겨질때 까지 반복
        if(arr[index_left] <= arr[index_right]){ // 분할된 두 그룹의 수를 각각 비교
            merged[index_merged] = arr[index_left]; // 더 작은 수를 병합 변수에 삽입
            index_left++; // 다음 숫자 비교준비
        }
        else{
            merged[index_merged] = arr[index_right];
            index_right++;
        }
        index_merged++; // 다음 숫자 넣을 준비 
    }

    if(index_left > middle){ // 왼쪽 그룹이 병합 그룹에 다 들어갔다면 
        for(int i = index_right; i <= rightEnd; i++){ // 오른쪽 그룹의 남은 수를 병합
            merged[index_merged] = arr[i];
            index_merged++;
        }
    }
    else{                    // 오른쪽 그룹이 병합 그룹에 다 들어갔다면
        for(int i = index_left; i <= middle; i++){ // 왼쪽 그룹의 남은 수를 병합
            merged[index_merged] = arr[i];
            index_merged++;
        }
    }

    for(int i = leftStart; i <= rightEnd; i++){ // 병합된 수들을 본체에 삽입.
        arr[i] = merged[i];
    }
}

void mergeSort(int *arr, int left, int right){
    if(left < right){ // 분할할 수가 1개 이상일때 
        int divided = (left + right) / 2; // 반씩 분할
        mergeSort(arr, left, divided); // 분할된 왼쪽 그룹을 또 분할
        mergeSort(arr, divided + 1, right); // 분할된 오른쪽 그룹을 또 분할
        merge(arr, left, divided, right); // 분할 된 두 그룹을 병합
    }
}

int main(void){
    int arr[10] = {8, 7, 6, 0, 4, 9, 1, 3, 5, 2};

    mergeSort(arr, 0, n - 1); // 병합 정렬
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
