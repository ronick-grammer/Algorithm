#include <iostream>
using namespace std;

// 1. n 에서 1을 뺀다
// 2. n 을 k 로 나눈다
// 위 두가지 방법을 이용해서 1을 만들수 있는 최소횟수를 구한다
int main(void){
    int n, k;
    int cnt = 0;   

    cin >> n >> k;

    while(n != 1){
        
        if(n % k == 0){ // n 이 k로 나누어 떨어지면 나눈다
            n = n / k;
        }
        else{ // 그렇지 않으면 1을 빼준다.
            n--;
        }
        cnt++; // 최소 횟수 증가
    }

    cout<<cnt<<endl;
}
