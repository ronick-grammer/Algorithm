//problem link: https://programmers.co.kr/learn/courses/30/lessons/42839
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int primeNumber[10000000];
bool primeNumberVisited[10000000];

int solution(string numbers) {
    
    int answer = 0;
    vector<int> num;
    
    // 소수 처리하기 (에라이프로토스아테네스의 체)
    primeNumber[0] = -1;
    primeNumber[1] = -1;
    for(int i = 2; i <= sqrt(9999999); i++) {
        
        if(primeNumber[i] == -1) continue;
        
        for(int j = i*i; j <= 9999999; j += i) {
            primeNumber[j] = -1;
        }
    }
    
    // 정렬한 후 조합가능한 모든 수를 소수인지 판별하기
    sort(numbers.begin(), numbers.end());
    do {
        
        // 숫자 갯수에 따른 조합 알아내기
        for(int i = 1; i <= numbers.size(); i++) {
            
            vector<bool> visited(numbers.size(), false);
            fill(visited.end() - i, visited.end(), true);
            
            do {
                
                string num = "";
                
                for(int j = 0; j < visited.size(); j++) {
                    if(visited[j]) {
                        num += numbers[j];
                    }
                }
                
                int index = stoi(num);
                // 중복 처리 피해주기
                if(!primeNumberVisited[index] && primeNumber[index] == 0) {
                    answer++;
                    primeNumberVisited[index] = true;
                }
                    
            // 갯수에 따른 모든 수
            } while(next_permutation(visited.begin(), visited.end()));
            
        }
        
    // 순서를 바꾼 모든 수
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}
