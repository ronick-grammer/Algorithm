#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n, m, k;
    vector<int> v;

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end()); // 오름차순하여 가장 큰수와 두번 째로 큰 수를 구한다
    
    int count_first_max = (m / (k + 1)) * k; // 가장 큰 수가 더해지는 횟수
    count_first_max += (m % (k + 1));

    int count_second_max =  m - count_first_max; // 두번째로 큰 수가 더해지는 횟수

    int result = (count_first_max * v[v.size()-1]) + (count_second_max * v[v.size() - 2]);
    cout<<result<<endl;
}
