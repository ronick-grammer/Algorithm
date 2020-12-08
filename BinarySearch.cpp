#include <iostream>
using namespace std;

int n = 8; // 숫자의 갯수
int arr[8] = {2, 4, 6, 8, 10, 12, 14, 16}; // 이진탐색은 정렬이 되어 있는 상태에서만 사용할 수 있다

int binarySearch(int value , int start, int end){ // value: 탐색할 숫자
    if(start < end){ // 비교할 숫자가 두개이상일때 이진탐색 가능
        int index_mid = (start + end) / 2; // 중간점을 찾는다
        if(arr[index_mid] < value) // 탐색하는 값이 중간 값보다 크면
        {
            return binarySearch(value, index_mid + 1, end); // 중간값 오른쪽에 탐색하는 값이 존재한다
        }
        else if(arr[index_mid] > value) // 탐색하는 값이 중간 값보다 작으면
        {
            return binarySearch(value, start, index_mid - 1); // 중간값 왼쪽에 탐색하는 값이 존재한다
        }
        else{   // 탐색 성공
            return index_mid + 1; // 인덱스는 0 부터 시작하므로 1 을 더해서 반환
        }
    }
    else{ // 탐색 실패
        return -1; // 탐색 실패의 의미로 -1 을 반환
    }
}

int main(void){
    int s; 
    cin>>s; // 탐색할 숫자 입력
    cout<<binarySearch(s, 0, n - 1)<<" 번째 위치에 "<<s<<" 가 있음";
}
