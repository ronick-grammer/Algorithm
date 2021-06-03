//problem link: https://www.acmicpc.net/problem/13335
#include <iostream>
#include <queue>
using namespace std;

int truck[1001];
int main(void){

    int n, w, l;

    cin >> n >> w >> l;
    for(int i = 0; i < n; i++){
        scanf(" %d", &truck[i]);
    }

    queue<int> q;
    int current_weight = 0;
    int min_seconds = 0;
    for(int i = 0; i < n; i++){
        while(1){ 
            if(q.size() == w){
                current_weight -= q.front();
                q.pop();
            }

            if(current_weight + truck[i] <= l){
                break;
            }

            min_seconds++;
            q.push(0);
        }

        q.push(truck[i]);
        current_weight += truck[i];
        min_seconds++;
    }
    cout<<min_seconds + w<<'\n';
}
