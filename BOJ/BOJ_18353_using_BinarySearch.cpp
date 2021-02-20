#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//problem link: https://www.acmicpc.net/problem/18353

// LIS 알고리즘을 이용하면 N^2의 시간복잡도이기 떄문에
// 이진탐색을 이용하여 O(NlogN)의 시간복잡도로 해결하기로 한다.
// 이 문제의 풀이 핵심은 병사들의 전투력 범위가 촘촘해야 최대 값을 뽑을 수 있다는 것이다.
// 예를 들어 15, 14, 8, 2... 보다 15, 14, 8, 7... 로 해야 7 뒤에 6 ~ 1 의 숫자가 더 붙을 수 있다.
// 2 뒤에는 1 밖에 붙을 수 없기때문에 이를 유의해야 한다.

int soldiers[2001];
vector<int> max_soldiers;

int main(void){
    int n;

    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        soldiers[i] = x;
    }

    max_soldiers.push_back(-soldiers[0]); // 내림차순을 위해 '-'를 붙여준다.
    for(int i = 1; i < n; i++){
        int x = -soldiers[i]; // 내림차순 비교를 위해 '-'를 붙여준다.
        // (-마지막 병사의 전투력 < -현재 병사의 전투력) == (마지막 병사의 전투력 > 현재 병사의 전투력)
        if(max_soldiers.back() < x){ 
            max_soldiers.push_back(x);
        }
        else{
            // 이진 탐색을 이용하여 x 전투력보다 크거나 같은 수의 위치를 찾자.
            // '-' 기호가 붙어있기때문에 사실상 x전투력보다 작거나 같은 수의 위치를 찾는 것이나 마찬가지이다.
            vector<int>::iterator left = lower_bound(max_soldiers.begin(), max_soldiers.end(), x);
            max_soldiers[left - max_soldiers.begin()] = x;
        }
    }
    cout<<n - max_soldiers.size()<<'\n';
}
