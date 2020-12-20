#include <iostream>
#include <algorithm>
using namespace std;

// 1. 1을 뺀다.
// 2. 2 로 나누어 떨어지면 2로 나눈다.
// 3. 3으로 나누어 떨어지면 3로 나눈다.
// 4. 5 로 나누어 떨어지면 5로 나눈다.
/// 각각의 방법을 이용할 때마다 연산횟수가 1씩 증가한다.
/// 위 네가지 방법을 이용하여 특정숫자를 1로 만드는 최소연산 횟수를 구한다.

int arr[30001];

int main(void){
    int x;
    cin>>x;

    arr[2] = arr[3] = arr[5] = 1; // x가 2 or 3 or 5 이면 한번에 나누어 떨어진다.
    arr[4] = 2; // x가 4이면 최소 두번만에 1로 만들어진다(4/2 -> 2/2 == 1, 4-1 -> 3/3 == 1)

    for(int i = 6; i <= x; i++){
        arr[i] = arr[i-1] + 1; // -1을 했으므로 연산횟수 +1, 그리고 arr[i-1]에는 이미 최소 연산횟수가 저장되어있으므로 추가 연산은 없다
        
        //이제 위의 -1한 경우의 횟수와 비교해준다

        // -1을 하지 않은 수가 2로 나누어 떨어질 경우,
        // '-1한 경우의 최소횟수' 와 '2로 나눈 경우의 최소횟수' 를 비교해 대입
        if(i % 2 == 0){  
            arr[i] = min(arr[i], arr[i/2] + 1); 
        }

        // -1을 하지 않은 수가 3으로 나누어 떨어질 경우,
        // '-1한 경우의 최소횟수' or '2로 나눈 경우의 최소횟수' 와 '3으로 나눈 경우의 최소횟수'를 비교해 대입
        if(i % 3 == 0){ 
            arr[i] = min(arr[i], arr[i/3] + 1); 
        }

        // -1을 하지 않은 수가 5로 나누어 떨어질 경우,
        // '-1한 경우의 최소횟수' or '2로 나눈 경우의 최소횟수' or '3으로 나눈 경우의 최소횟수' 와 '5로 나눈 경우의 최소 횟수'를 비교해 대입
        if(i % 5 == 0){ 
            arr[i] = min(arr[i], arr[i/5] + 1); 
        }
        
    }

    cout<<arr[x]<<endl;
}