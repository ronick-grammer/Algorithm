#include <iostream>
#include <algorithm>
using namespace std;


// 1. 1을 뺀다.
// 2. 2 로 나누어 떨어지면 2로 나눈다.
// 3. 3으로 나누어 떨어지면 3로 나눈다.
// 4. 5 로 나누어 떨어지면 5로 나눈다.
/// 위 네가지 방법을 이용하여 1로 만드는 최소연산 횟수를 구한다.
/// 다이나믹 프로그래밍으로 푸는 것이 가장 이상적이지만, 생각나는 대로 무작위 구현을 해보았다. 
int main(void){
    int x, count = 0;
    cin>>x;
 
    while(x != 1){
        int n = x;
        int c = x - 1; // 1. 1을 뺀다.
        int temp_count = count; // 임시 연산횟수

        if(x % 2 == 0){ // 2. 2로 나누어 떨어지면 2로 나눈다.
            n = x / 2;
            temp_count = count + 1; // 연산횟수는 한번만 증가.
        }
        if(x % 3 == 0){ // 3. 3으로 나누어 떨어지면 3으로 나눈다.
            n = min(x / 3, n); // 2와 3 두 숫자 모두와 나누어 떨어지는 것들 중 가장 적게 나누어 지는수를 택한다. 예를 들어 (6 / 3) < (6 /3) 
            temp_count = count + 1;
        }
        if(x % 5 == 0){ // 4. 5로 나누어 떨어지면 5로 나눈다.
            n = min(x / 5, n); // 3와 5 두 숫자 모두와 나누어 떨어지는 것들 중 가장 적게 나누어 지는수를 택한다.  예를 들어 (30 / 5) < (30 /3)
            temp_count = count + 1;
        }

        if(c % 2 == 0){  // 1이 빼진 숫자가 2로 나누어 떨어지면
            if(n != min(c / 2, n)){ // (1이 빼진 숫자 / 2) <  (1이 안빼진 숫자 / 2 or 3 or 5) 이면 --> 위의 if문 
                temp_count = count + 2; // -1 을 하고  / 2 를 한것이므로 2번의 연산횟수 증가 
            }
                n = min(c / 2, n);
        }
        if(c % 3 == 0){ // 1이 빼진 숫자가 3로 나누어 떨어지면
            if(n != min(c / 3, n)){ // (1이 빼진 숫자 / 3) <  (1이 안빼진 숫자 / 2 or 3 or 5) 이면 --> 위의 if문 
                temp_count = count + 2; // -1 을 하고  / 3 를 한것이므로 2번의 연산횟수 증가 
            }
                n = min(c / 3, n);
        }
        if(c % 5 == 0){ // 1이 빼진 숫자가 5로 나누어 떨어지면
             if(n != min(c / 5, n)){ // (1이 빼진 숫자 / 5) <  (1이 안빼진 숫자 / 2 or 3 or 5) 이면 --> 위의 if문 
                temp_count = count + 2; // -1 을 하고  / 5 를 한것이므로 2번의 연산횟수 증가 
            }
                n = min(c / 5, n);
        }

        x = n;
        count = temp_count;
        //cout<<x<<endl;
    }

    cout<<count<<endl;
}