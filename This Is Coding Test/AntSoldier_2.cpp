#include <iostream>
#include <algorithm>
using namespace std;

// 개미전사 //
// 일직선상 '최소 한 칸 이상' 떨어진 식량 착고를 약탈해서 
// 얻을 수 있는 최대 식량 값을 구한다.

int arr[100];

int main(void){
    int n;
    cin>>n; // 식량 창고 갯수
    
    for(int i = 0; i < n; i++){
        cin >> arr[i]; // 식량의 갯수
    }

   // 4번째 창고를 털었을때를 가정하였을떄, 13, 5, 6, 8 일때  2번째 창고(5개) + 4번째 창고(8개) = 13개 가 아니라
   // 1번째 창고(13개) + 4번째 창고(8개) = 21개 를 해야 최대값을 차곡차곡 저장 가능.
    arr[1] = max(arr[0], arr[1]); 

    for(int i = 2; i < n; i++){ 
        arr[i] = max(arr[i-1], arr[i-2] + arr[i]); // 왼쪽 창고부터 식량을 차곡 차곡 쌓는다.
    }

    // 한칸 떨어진 창고부터 털었을 때와 두칸 떨어졌을 때부터 털었을 때 얻은 식량의 갯수중 최대 갯수를 출력
    cout<<max(arr[n-1], arr[n-2])<<endl;
}
