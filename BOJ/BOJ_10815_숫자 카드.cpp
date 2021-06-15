//problem link: https://www.acmicpc.net/problem/10815
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
priority_queue<int> card_a;
priority_queue<pair<int, int> > card_b;
int result[500000];

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        scanf(" %d", &x);
        card_a.push(-x);
    }

    cin>>m;
    for(int i = 0; i < m; i++){
        int x;
        scanf(" %d", &x);
        card_b.push(make_pair(-x, i));
    }

    while(!card_a.empty() && !card_b.empty()){
        int a = -card_a.top();
        int b = -card_b.top().first;
        if(a == b){
            card_a.pop();
            card_b.pop();
            result[card_b.top().second] = 1;
        }
        else if(a > b){
            card_b.pop();
        }
        else{
            card_a.pop();
        }
    }

    for(int i = 0; i < m; i++){
        cout<<result[i]<<' ';
    }
    cout<<'\n';
}

// -10  2 3 6 10
// -10 -5 2 3  4  5 9 10 
