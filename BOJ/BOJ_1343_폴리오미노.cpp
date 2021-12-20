// 아 코드 진짜 맘에 안드네,,
//problem link: https://www.acmicpc.net/problem/1343
#include <iostream>
#include <string>
using namespace std;

string str_aaaa = "AAAA";
string str_bb = "BB";

int main(void) {
    string str;
    cin>>str;
    
    // X 한글자만 입력했을시에 -1
    if(str.size() == 1 && str == "X") {
        cout<<"-1"<<endl;
        return 0;
    }
    int pos = 0;
    int current = 0;
    int count = str.size();
    string answer = "";

    while((pos = str.find('.', pos)) != string::npos) {
        count = pos - current;

        // 홀수개이면 무조건 -1
        if(count % 2 == 1) {
            cout<<"-1"<<endl;
            return 0;
        }
        
        // '.' 이 연속되면 바로 뒤에 붙이고 다시 반복하기
        if(count == 0) {
            answer += ".";
            current = ++pos;
            continue;
        }

        // 4개 이상이면 "AAAA" 붙이기
        if(count >= 4) {
            for(int i = 0; i < count / 4; i++) {
                answer += str_aaaa;
            }
            count = count % 4;
        }

        // "AAAA" 를 붙이고 나서 "BB"를 붙일수 있으면 붙이기
        if(count >= 2) {
            answer += str_bb;
        }

        // 마지막에 '.' 붙이기
        answer += ".";

        // 찾을 위치 갱신
        current = ++pos;    
        
    }

    // 마지막 문자열은 따로 해줘야함
    count = str.size() - current;

    // 홀수개이면 무조건 -1
    if(count % 2 == 1) {
        cout<<"-1"<<endl;
        return 0;
    }
    
    if(count >= 4) {
        for(int i = 0; i < count / 4; i++) {
            answer += str_aaaa;
        }
        count = count % 4;
    }

    if(count >= 2) {
        answer += str_bb;
    }

    cout<<answer<<endl;
}
