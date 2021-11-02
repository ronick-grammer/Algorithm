#include <string>
#include <vector>
using namespace std;

// 두 수의 최대 합: 200
bool exists[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 두 수를 뽑아서 더하는 모든 경우를 구하기(n이 200밖에 안되니까 200^2 시간복잡도)
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            // 중복 제거
            if(!exists[sum]) {
                exists[sum] = true;
            }
        }
    }
    
    
    for(int i = 0; i <= 201; i++) {
        if(exists[i]) answer.push_back(i);
    }
    
    return answer;
}
