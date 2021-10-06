#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool visited[101];
vector<int> arr[101];
int fromPerson, toPerson;
int result = -1;

void dfs(int to, int number) {
    
    if (to == toPerson) { // 촌수알아내고자 하는 사람이면 그값 저장
        result = number;
        return;
    }

    for(int i = 0; i < arr[to].size(); i++) {
        if (!visited[arr[to][i]]) {
            visited[arr[to][i]] = true;
            dfs(arr[to][i], number + 1); // 한명 한명 옮겨갈때 마다 촌수는 +1
        }
    }
}

int main(void) {
    int numberOfPeople;
    int numberOfRelations;

    cin >> numberOfPeople;
    cin >> fromPerson >> toPerson;
    cin >> numberOfRelations;

    for(int i = 0; i < numberOfRelations; i++) {
        int parent, child;
        scanf("%d %d", &parent, &child);

        arr[parent].push_back(child);
        arr[child].push_back(parent);
    }

    dfs(fromPerson, 0); // 출발
    if(result != -1 ) cout<<result<<'\n';
    else cout<<result<<'\n';
}
