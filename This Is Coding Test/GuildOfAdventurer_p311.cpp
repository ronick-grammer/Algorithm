#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
vector<int> v;
int count_member, result; // count_member : 현재 팀 멤버, result = 최대 팀 수

int main(void){
    cin>>n;
    for(int i = 0; i < n; i++) { // 각 멤버의 공포도를 입력
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 최대 팀의 수를 얻으려면 적은 공포도를 가진 멤버부터 시작하여야 한다

    for(int i = 0; i < n; i++) {
        count_member++; // 일단 해당 팀에 멤버 한명을 포함 시킨다
        if(count_member >= v[i]){ // 그리고 그 팀의 방금까지 포함시킨 멤버수가 방금 그 멤버의 공포도랑 같거나 크면 팀 하나의 구성 완료
            result++; // 구성된 팀을 증가시킨다
            count_member = 0; // 새로운 팀을 짜기 위해 초기화
        }
    }
    cout<<result<<endl;
}
