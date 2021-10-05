#include <iostream>
#include <utility>
using namespace std;

pair<int, int> people[50];

int main(void){
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &people[i].first, &people[i].second);
    }

    // n <= 50 이기 때문에, n^2 시간 복잡도도 이중 반복문으로 거뜬히 수행가능
    for(int i = 0; i < n; i++) {
        int rank = 1;

        for(int j = 0; j < n; j++) { // 자신보다 높은 사람이 있다면 랭크를 1씩 높임
            if (people[i].first < people[j].first && people[i].second < people[j].second) {
                rank++;
            }
        }
        cout<<rank<<" ";
    }
}
