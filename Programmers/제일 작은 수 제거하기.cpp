//problem link: https://programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    // 1개 이하면 -1 
    if(arr.size() < 2) answer.push_back(-1);
    else {
        int minNum = arr[0];
        int minIndex = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(minNum > arr[i]) {
                minNum = arr[i];
                minIndex = i;
            }
        }
        arr.erase(arr.begin() + minIndex);
        answer = arr;
    }
    
    return answer;
}
