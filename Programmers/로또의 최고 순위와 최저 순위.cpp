//problem link: https://programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>
using namespace std;
int win_num[46]; // 로또 번호가 45까지므로 배열로 선언해도 메모리 부담이 없다.
int ranking[7] = {6, 6, 5, 4, 3, 2, 1}; // 각각 맞춘 갯수[index]에 따라 순위 결정

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    for(int i = 0; i < 6; i++){
        win_num[win_nums[i]] = true; // 우선 당첨 번호를 저장 
    }
    
    int answer_count = 0; // 당첨번호와 일치하는 번호들
    int zero_count = 0; // 낙서로 확인할 수 없는 번호들
    for(int i = 0; i < 6; i++){
        if(lottos[i] == 0){
            zero_count++;
        }
        else if(win_num[lottos[i]]){
           answer_count++;
        }
    }

    answer.push_back(ranking[zero_count + answer_count]); // 낙서된 번호들도 전부 맞춰다고 가정하면 된다.
    answer.push_back(ranking[answer_count]); // 반대로 낙서된 번호들이 전부 틀렸다고 가정하면 된다.
    return answer;
}
