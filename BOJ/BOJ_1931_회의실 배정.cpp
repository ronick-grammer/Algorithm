//problem link: https://www.acmicpc.net/problem/1931
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int, int> meetings[100001];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main(void){
    cin>>n;
    for(int i = 1; i <= n; i++){
        int start, end;
        scanf(" %d %d", &start, &end);
        meetings[i] = make_pair(start, end);
    }

    sort(meetings, meetings + n + 1, compare); // 끝나는 시간 기준으로 정렬

    int result = 0;
    int current_end = 0; // 최근에 끝난 최저 시간
    for(int i = 1; i <= n; i++){
       if(current_end <= meetings[i].first){ // 최근 회의가 끝난 시간 이후부터 시작할 수 있는 회의라면
           result++;
           current_end = meetings[i].second; // 다음 회의가 끝나는 시간으로 갱신
       }
    }

    cout<<result;
}
