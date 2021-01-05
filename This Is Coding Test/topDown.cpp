#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 내림차순 정렬

int n;
vector<int> v;

bool compare(int a, int b){
    return a > b;
}

int main(void){
    cin>>n;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}
