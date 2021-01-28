#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/60062

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    int length = weak.size(); // 기존의 취약점 갯수를 저장
    
    for(int i = 0; i < length; i++){ // 원을 일자로 만들기
        weak.push_back(weak[i] + n);
    }

    for(int start = 0; start < length; start++){ // 취약점의 갯수만큼 반복
        do { // 각 취약점에서 매번 다른 순서로 출발할 수 있는 모든 경우의 수만큼 진행한다
            int count = 1; // 처음에는 출발하는 한명의 사람
            int current_position = weak[start] + dist[count - 1]; // 처음 출발하는 사람의 도착점

            for(int index = start; index < start + length; index++){ // 출발 취약지점에서 마지막 취약지점까지 돈다
               
                if(current_position < weak[index]){  // 현재 사람이 해당 취약지점까지 갈 수 없으면
                    count++; // 다음 사람을 보낸다

                    if(count > dist.size()){ // 근데 그 다음 사람이 인원을 초과할 수는 없다.
                        break;
                    }
                    current_position = weak[index] + dist[count - 1]; // 그 다음 사람이 해당 취약지점에서 출발하여 도착하는 지점
                }
            }
            answer = min(answer, count); // 최소 인원을 구한다
        }while(next_permutation(dist.begin(), dist.end()));
    }

    if(answer > dist.size()){ // 사람들을 모두 투입해도 취약점을 전부 점검할 수 없는 경우
        return -1;
    }
    
    return answer;
}
