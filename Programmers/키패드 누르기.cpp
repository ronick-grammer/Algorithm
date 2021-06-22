//problem link: https://programmers.co.kr/learn/courses/30/lessons/67256?language=cpp
#include <string>
#include <vector>
#include <utility>
using namespace std;

bool check_left(int number){
    if(number == 1 || number == 4 || number == 7)
        return true;
    
    return false;
}

bool check_right(int number){
    if(number == 3 || number == 6 || number == 9)
        return true;
    
    return false;
}

string solution(vector<int> numbers, string hand) {
    pair<int, int> keyPad[10];
    int number = 1; // 1번 키패드
    for(int i = 0; i < 3; i++){ // 숫자 키별로 키패드의 좌표를 저장
        for(int j = 0; j < 3; j++){
            keyPad[number++] = make_pair(i, j);
        }
    }
    keyPad[0] = make_pair(3, 1);
    
    string answer = "";
    pair<int, int> current_L = make_pair(3, 0); // 왼 검지는 * 키패드에 처음 위치
    pair<int, int> current_R = make_pair(3, 2); // 오른 검지는 # 키패드에 처음 위치
    
    for(int i = 0; i < numbers.size(); i++){
        if(check_left(numbers[i])){ // 왼 검지가 터치 할 수 있는지 확인
            current_L = keyPad[numbers[i]];
            answer += "L";
        }
        else if(check_right(numbers[i])){ // 오른 검지가 터치할 수 있는지 확인
            current_R = keyPad[numbers[i]];
            answer += "R";
        }
        else{ // 중간 키패드들이면
            int diff_L = abs(current_L.first - keyPad[numbers[i]].first) +
                abs(current_L.second - keyPad[numbers[i]].second);
            int diff_R = abs(current_R.first - keyPad[numbers[i]].first) +
                abs(current_R.second - keyPad[numbers[i]].second);
            if(diff_L < diff_R){ // 왼 검지가 더 가까우면
                current_L = keyPad[numbers[i]];
                answer += "L";
            }
            else if(diff_L > diff_R){ // 오른 검지가 더 가까우면
                current_R = keyPad[numbers[i]];
                answer += "R";
            }
            else{ // 동일할 경우
                if(hand == "left"){ // 왼손 잡이일 경우
                    current_L = keyPad[numbers[i]];
                    answer += "L";
                }
                else{ // 오른손 잡이일 경우
                    current_R = keyPad[numbers[i]];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}
