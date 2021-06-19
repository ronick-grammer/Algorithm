//problem link: https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main(void) {
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int count = 0;
    cout<<'<';
    while(!q.empty()){
        count++;
        int x = q.front();
        q.pop();
        
        if(count == k){ // 남은 사람중 k번째
            if(q.empty())
                cout<<x;
            else
                cout<<x<<", ";
            count = 0; // 제거된 자리부터 다시 시작
        } 
        else q.push(x);
    }
    cout<<'>';
}
