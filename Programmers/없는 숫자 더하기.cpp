//problem link: https://programmers.co.kr/learn/courses/30/lessons/86051
#include <string>
#include <vector>

using namespace std;

bool visited[10];

int solution(vector<int> numbers) {
    int answer = 0;
    
    for(int i = 0; i < numbers.size(); i++) {
        int x = numbers[i];
        visited[x] = true;
    }
    
    for(int i = 0; i <= 9; i++) {
        if (!visited[i]) {
            answer += i;
        }
    }
    
    return answer;
}
