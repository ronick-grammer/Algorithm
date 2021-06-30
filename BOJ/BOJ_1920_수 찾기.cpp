//problem link: https://www.acmicpc.net/problem/1920
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[100000];
pair<int, int> x[100000];
int result[100000];

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf(" %d", &a[i]);
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        int value;
        scanf(" %d", &value);
        x[i] = make_pair(i, value);
    }
    sort(a, a + n); // 오름차순 정렬
    sort(x, x + m, compare); // 얘는 위치정보까지 포함해서 정렬해야함

    queue<int> q_a;
    queue<pair<int, int> > q_x;
    for(int i = 0 ; i < n; i++){
        q_a.push(a[i]);
    }
    for(int i = 0; i < m; i++){
        q_x.push(make_pair(x[i].first, x[i].second));
    }

    while(!q_a.empty() && !q_x.empty()){
        if(q_a.front() == q_x.front().second){ // 같으면 x값 pop, a값을 pop하지 않는 이유는 중복값때문에
            result[q_x.front().first] = 1; 
            q_x.pop();
        }
        else if(q_a.front() > q_x.front().second){ // a가 더 크면 x에 다음 값이 있는지 확인하기 위해 x만 pop
            result[q_x.front().first] = 0;
            q_x.pop();
        }
        else if(q_a.front() < q_x.front().second){ // x가 더 크면 a에 값이 더 있을 수 있으므로 a만 pop
            q_a.pop();
        }
    }
    
    while(!q_x.empty()){ // 남은 것들은 전부 0
        result[q_x.front().first] = 0;
        q_x.pop();
    }
    
    for(int i = 0; i < m; i++){
        cout<<result[i]<<'\n';
    }
}
