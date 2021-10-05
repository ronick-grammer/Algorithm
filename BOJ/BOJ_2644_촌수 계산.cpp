#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool visited[101];
vector<int> arr[101];

int bfs(int from, int to) {
    queue<pair<int, int> > q;
    q.push(make_pair(from, 0)); // 현재 촌수 0

    while(!q.empty()) {
        int currentPerson = q.front().first;
        int currentNumber = q.front().second;
        q.pop();

        if(currentPerson == to) { // 목적지라면 바로 현재 촌수 반환
            return currentNumber;
        }

        for(int i = 0; i < arr[currentPerson].size(); i++) {
            int nextPerson = arr[currentPerson][i];
            int nextNumber = currentNumber + 1; // 한번 옮겨갈 때 마다 촌수는 +1

            if (!visited[nextPerson]) {
                visited[currentPerson] = true; // 중복연산 안되게 방문처리
                q.push(make_pair(nextPerson, nextNumber));
            }
        }
    }

    return -1; // 친인척 관계가 아니면 -1 반환
}

int main(void) {
    int numberOfPeople;
    int from, to;
    int numberOfRelations;

    cin >> numberOfPeople;
    cin >> from >> to;
    cin >> numberOfRelations;

    for(int i = 0; i < numberOfRelations; i++) {
        int parent, child;
        scanf("%d %d", &parent, &child);

        arr[parent].push_back(child);
        arr[child].push_back(parent);
    }

    cout<<bfs(from, to)<<endl;
}
