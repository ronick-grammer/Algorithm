#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//problem link: https://www.acmicpc.net/problem/10800

int n;
vector<pair<int, pair<int, int> > > v;
int results[200001]; // 결과
int pounds_perColor[200001]; // 컬러들에 따른 크기 합
int same_pounds[2001]; // 같은 크기를 가지는 공들의 크기 합

bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    if(a.second.second == b.second.second) // 크기가 같다면 
        return a.second.first < b.second.first; // 컬러가 더 낮은게 먼저

    return a.second.second < b.second.second;
}

int main(void){
    cin >> n;
    int sum_pounds = 0;
    for(int i = 0; i < n; i++){
        int color, pounds;
        cin >> color >> pounds;
        v.push_back(make_pair(i, make_pair(color, pounds)));
    }
    
    sort(v.begin(), v.end(), compare); // 오름 차순
    
    int sum = 0;
    for(int i = 0; i < n; i++){ // 가장 무게가 낮은 순으로 진행,
        int number = v[i].first;
        int color = v[i].second.first;
        int pounds = v[i].second.second;

        // 직전 공 크기와 색이 현재 공의 것과 같다면 직전 공이 사로잡은 공의 크기 합을 넣어준다.
        // 왜냐하면 색과 크기가 같으면 같은 결과값을 같는 것이 당연하기 때문이다.
        if(i != 0 && v[i-1].second.first == color && v[i-1].second.second == pounds)
            results[number] = results[v[i-1].first];
        // 그것이 아니라면, (현재 까지의 합) - (현재 까지 같은 색의 크기 합) - (현재까지 같은 크기의 크기 합) + 현재 크기
        // 가장 크기가 작은 공부터 높은 공 순으로 진행하기 때문에, 크기가 가장 낮은 공은 0을 필연적으로 가진다. 자기보다 크기가 낮은 공은 존재하지 않기 때문이다.
        // 그리고 그 다음으로 크기가 낮은 공은 그 직전 공의 크기보다 높기 때문에 그 직전공의 크기를 가질 수 있다. 그것이 바로 {sum} 이다. 
        // 색이 같은 공은 사로 잡을 수 없기에 현재까지 색이 같은 공들이 있다면 그 공들의 크기 합을 빼준다. 이 역할을 { pounds_perColor[color] } 가 해준다.
        // 또한 크기가 같은 공 역시 사로 잡을 수 없기에 현재까지 크기가 같은 공들이 있다면 그 공들의 크기 합을 빼준다. 이 역할은 { same_pounds[pounds] } 가 한다.
        else
            results[number] = sum - pounds_perColor[color] - same_pounds[pounds];

        pounds_perColor[color] += pounds; // 같은 컬러를 가지는 공들의 크기 합
        same_pounds[pounds] += pounds; // 같은 크기를 가지는 공들의 크기 합
        sum += pounds; // 모든 공들의 크기 합
    }

    for(int i = 0; i < n; i++){
        cout<<results[i]<<'\n';
    }
}
