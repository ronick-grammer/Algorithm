//problem link: https://www.acmicpc.net/problem/9655
#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin>>n;

    // "두사람이 완벽하게 게임을 했을때," 란 문구를 유심히 생각해 보면
    // 특정 갯수의 돌이 주어지면 승자는 이미 정해져 있다라는 것을 의미 한다.
    // 1개 혹은 3개의 돌만 가져 갈 수 있다는 조건이 있기 때문이다. 
    // 따라서 홀수개면 상근이가, 짝수개면 창영이가 이긴다.
    if(n % 2 == 1) cout<<"SK"<<endl;
    else cout<<"CY"<<endl;
}
