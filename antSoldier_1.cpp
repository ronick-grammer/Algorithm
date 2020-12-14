#include <iostream>
#include <algorithm>
using namespace std;

// 개미전사 //
// 일직선상 '최소 한 칸 이상' 떨어진 식량 착고를 약탈해서 
// 얻을 수 있는 최대 식량 값을 구한다.

// * 문제 해답과는 다르게 풀렸다. 이게 DP 방식이 맞는지는 불확실하다. 
int arr[100];

int main(void){
    int n;
    cin>>n; // 식량 창고 갯수
    
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // 식량의 갯수
    }

    arr[2] = arr[0] + arr[2];
    for(int i = 3; i < n; i++){
        int n1 = arr[i] + arr[i-2]; // '현재 창고' 와 '왼쪽에 한칸 떨어진 창고' 를 털어 얻은 식량의 갯수
        int n2 = arr[i] + arr[i-3]; // '현재 창고' 와 '왼쪽에 두칸 떨어진 창고' 를 털어 얻은 식량의 갯수
        arr[i] = max(n1, n2);       // 위 두 식량의 갯수들 중 더 많은 식량의 갯수를 현재 창고에 저장한다.
    }
    
    // 한칸 떨어진 창고부터 털었을 때와 두칸 떨어졌을 때부터 털었을 때 얻은 식량의 갯수중 최대 갯수를 출력
    cout<<max(arr[n-1], arr[n-2])<<endl; 
}
