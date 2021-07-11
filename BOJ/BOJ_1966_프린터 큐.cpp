//problem link: https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main(void) {
    int tc;
    cin >> tc;
    
    for(int i = 0; i < tc; i++){
        int n, m;
        cin >> n >> m;

        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;

            q.push(make_pair(j, x));
            pq.push(x); // 가장 높은 중요도 순으로 
        }

        int rank = 1; 
        while(!q.empty()) {
            int num = q.front().first;
            int priority = q.front().second;
            q.pop();

            if(priority < pq.top()) { // 현재문서보다 중요도가 높은 문서가 있다면
                q.push(make_pair(num, priority)); // 가장 뒤에 재배치
            } else { // 현재문서가 가장 높은 중요도를 가졌다면
                if(num == m) { // 내가 궁금해하는 문서가 맞는지 체크
                    cout<<rank<<'\n'; // 맞다면 출력
                    break;
                }
                
                pq.pop(); // 다음으로 가장 높은 중요도로
                rank++;  // 다음으로 가장 높은 중요도로
            }
        }
    }
}
