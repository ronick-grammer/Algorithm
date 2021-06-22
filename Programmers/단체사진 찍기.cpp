//problem link: https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool validate(char comp, int diff, int offset){
    if(comp == '=')
        return diff == offset;
    else if(comp == '<')
        return diff < offset;
    else
        return diff > offset;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    // next_permutation 함수를 쓰려면 처음에 오름차순으로 정렬되어 있어야 한다.
    string s = "ACFJMNRT"; 
    do{ // 모든 경우를 돌면서 각 프렌즈들의 조건에 맞게 서로 거리가 적절한지 체크한다.
        int flag = true;
        for(int i = 0; i < n; i++){
            char f1 = data[i][0];
            char f2 = data[i][2];
            char comp = data[i][3];
            int offset = data[i][4] - '0';
            
            // 두 친구의 거리를 계산
            int diff = abs((int)s.find(f1) - (int)s.find(f2)) - 1;
            
            if(!validate(comp, diff, offset)){ // 유효하지 않으면 
                flag = false;
                break;
            }
        }
        if(flag) // 유효하면 카운트
            answer++;
    }while(next_permutation(s.begin(), s.end()));
    return answer;
}
