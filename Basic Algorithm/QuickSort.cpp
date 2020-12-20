#include <iostream>
#include <algorithm>
using namespace std;

int n = 10;
int arr[10] = {8, 7, 6, 0, 4, 9, 1, 3, 5, 2};

void quickSort(int *arr, int start, int end)
{
    if(start >= end) return; // 1개 이하면 종료

    int pivot = start;
    int max = start + 1; // 피봇다음 값부터
    int min = end;

    while(max <= min){  // 큰수와 작은수가 엇갈릴때까지 반복 , 비교할 수가 피봇포함 두개일 경우떄문에 = 도 씀
        while(max <= end && arr[pivot] > arr[max]){ // 큰수를 찾아 오른쪽으로
            max++;
        }
        while(min > start && arr[pivot] < arr[min]){ // 작은수를 찾아 왼쪽으로
            min--;
        }

        if(max > min){  // 큰수와 작은수가 서로 엇갈렸다면 피봇과 최솟값 교환
            swap(arr[pivot], arr[min]);
        }
        else{   // 엇갈리지 않았다면 작은수와 큰수 교환
            swap(arr[min], arr[max]);
        }
    }

    quickSort(arr, start, min - 1); // 분할된 피봇보다 작은수 그룹 정렬
    quickSort(arr, min + 1, end);   // 분할된 피봇보다 큰수 그룹 정렬
}

int main(void){
    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
