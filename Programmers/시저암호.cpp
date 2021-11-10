#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++) {
        // 공백 아니면
        if(s[i] != ' ') {
            // 밀었을때 'z' or 'Z'를 넘어가면 'a' or 'A' 부터 시작해 남은 거리만큼 밀기
            if(islower(s[i]) && s[i] + n > 'z')
                answer += 'a' + (s[i] + n - 'z') - 1;
            else if(isupper(s[i]) && s[i] + n > 'Z')
                answer += 'A' + (s[i] + n - 'Z') - 1; 
            else
                answer += s[i] + n; // 무난하게 밀기
        }
        else{
            answer += " ";
        }
    }
    return answer;
}
