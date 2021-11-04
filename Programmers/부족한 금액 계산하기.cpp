//problem link: https://programmers.co.kr/learn/courses/30/lessons/82612
#include<algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    // count 최대 2500, price 최대 2500 이라서
    // 범위가 넓은 타입으로 선언해야함
    long long sum = 0; 
    for(int i = 1; i <= count; i++) {
        sum += (price * i);
    }
    
    answer = money - sum;
    
    // 금액이 부족하지 않으면
    if(answer >= 0) return 0;
    
    // 부족한 금액 리턴
    return abs(answer);
}
