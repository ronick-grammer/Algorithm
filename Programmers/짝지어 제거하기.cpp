//problem link: https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 굉장히 쉬운문제였다.

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(st.empty() || st.top() != s[i]){ // 스택이 비어있거나 앞의 두 글자가 같지 않으면 그대로 스택에 쌓아둔다.
            st.push(s[i]);
        }
        else if(st.top() == s[i]) {  // 앞의 두 글자가 같다면 스택에 넣어 두었던 앞 글자를 pop
            st.pop();
        }
    }
    
    if(st.empty()) return 1;
    else return 0;
}
