//problem link: https://www.acmicpc.net/problem/11650
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) // x 좌표가 같으면 
        return a.second < b.second; // y 좌표가 낮은게 먼저 오도록 
    
    return a.first < b.first; // x 좌표가 낮은 순으로
}

int main(void) {
    int n;
    pair<int, int> coordinate[100000];

    cin >> n;
    for(int i = 0;  i < n; i++) {
        int x, y;
        cin >> x >> y;
        coordinate[i] = make_pair(x, y);
    }

    sort(coordinate, coordinate + n, compare);

    for(int i = 0; i < n; i++) {
        int x = coordinate[i].first;
        int y = coordinate[i].second;
        cout<<x<<' '<<y<<'\n';
    }
}
