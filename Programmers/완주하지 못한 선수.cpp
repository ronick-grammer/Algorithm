//problem link: https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> sameParticipant;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    string answer = "";
    
    // '완주하지 못한 단 한명의 선수'인게 핵심
    for(int i = 0; i < participant.size(); i++) {
        if(participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}
