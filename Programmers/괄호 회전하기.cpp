//problem link: https://programmers.co.kr/learn/courses/30/lessons/76502
#include <string>
#include <queue>
#include <stack>
using namespace std;

bool validate(queue<char> q) {

    stack<char> st;
    
    while(!q.empty()) {
        char bracket = q.front();
        q.pop();
        
        if(bracket == '[' || bracket == '{' || bracket == '(') {
            st.push(bracket);
            continue;
        }
        // 시작 괄호보다 끝 괄호가 먼저면 false
        else if(st.empty()) return false; 
        // 끝 괄호이면 최근의 시작괄호와 같은 타입인지 비교
        else if(bracket == ']' && st.top() != '[') return false;
        else if(bracket == '}' && st.top() != '{') return false;
        else if(bracket == ')' && st.top() != '(') return false;
        
        st.pop();
        
    }
    
    return true;
}

int solution(string s) {
    
    // 짝이 맞지 않으면 0 반환
    if(s.size() % 2 == 1) return 0;
    
    int answer = 0;
    queue<char> q;
    
    for(int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }
    
    for(int i = 0; i < s.size(); i++) {
        
        if(validate(q)) answer++;
        
        // 회전 시키기
        q.push(q.front());
        q.pop();
    }
    
    return answer;
}
