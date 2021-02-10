#include <iostream>
#include <queue>
using namespace std;

//problem link: https://www.acmicpc.net/problem/1715

int main(void){
    int n;
    priority_queue<int> pq;

    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(-x); // 작은 숫자가 가장 위로 오게한다
    }

    int result = 0; // n 이 1인 경우에는 0

    while(pq.size() > 1){
        // 맨 위에 있는 가장 적은 수를 가지는 두개의 카드를 빼낸다.
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();

        int sum = a + b; // 그리고 더한다.
        pq.push(-sum); // 더한걸 다시 넣어 오름차순으로 정렬

        result += sum; // 더한 값들을 축적한다
    }
    cout<<result<<'\n';
}
