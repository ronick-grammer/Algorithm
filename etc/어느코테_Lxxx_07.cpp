#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> input;
vector<int> result;

int arr[100000];

pair<int, int> current_index;

bool compare(pair<int, int> a, pair<int, int> b){
    int a_diff = abs(current_index.second - a.second);
    int b_diff = abs(current_index.second - b.second);

    // current_index의 원소와 같다면 맨 뒤로 보냄
    if(a.first == current_index.first) 
        return false;
    if(b.first == current_index.first)
        return true;
    
    // 큰 값들중 인덱스 거리가 같은 것이 여러 개라면 작은 인덱스가 앞에 오도록 함
    if(a_diff == b_diff)
        return a.second < b.second;
    

    return a_diff < b_diff; // 인덱스 거리가 적은 것이 앞에 오도록
}

vector<int> solution(vector<int> input){
    vector<int> answer(input.size(), 0);
    vector<pair<int, int> > temp;
    
    for(int i = 0; i < input.size(); i++){
        temp.push_back(make_pair(input[i], i));
    }
    
    sort(temp.begin(), temp.end());
    answer[temp[temp.size() - 1].second]  = -1; // 가장 큰 원소이므로 -1
    answer[temp[temp.size() - 2].second]  = temp[temp.size() - 1].second; // 두번 째로 큰 원소는 가장 큰 원소의 인덱스를 가짐

    for(int i = temp.size() - 3; i >= 0; i--){ // 세 번째로 큰 원소부터 진행
        // 현재 원소를 기준으로 큰 원소들만을 정렬함
        current_index = make_pair(temp[i].first, temp[i].second);
        sort(temp.begin() + i + 1, temp.end(), compare);

        // 거리가 가장 가까운 큰 원소 저장
        answer[temp[i].second] = temp[i + 1].second;
    }

    return answer;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        input.push_back(x);
    }
    result = solution(input);

    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<' ';
    }
    cout<<'\n';
}
