//problem link: https://programmers.co.kr/learn/courses/30/lessons/87946
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 이건 정말 쉬웠다!!!!
int solution(int k, vector<vector<int>> dungeons) {

    vector<int> visited;
    //순열을 구하기 위해 next_permutaion 사용하려면 오름차순으로 저장해야함
    for(int i = 0; i < dungeons.size(); i++) {
        visited.push_back(i);
    }
    
    // 던전의 최대 갯수가 8이므로 순열로 모든 경우의 수를 구해도 무리가 없다.
    int maxCount = 0;
    do {
        int count = 0;
        int hp = k;
        for(int i = 0; i < visited.size(); i++) {
            int number = visited[i];
            if(dungeons[number][0] <= hp) {
                hp -= dungeons[number][1];
                count++;
            } else {
                break;
            }
        }
        maxCount = max(maxCount, count);
    } while(next_permutation(visited.begin(), visited.end()));
    
    return maxCount;
}
