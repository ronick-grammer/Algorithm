//problem link: https://programmers.co.kr/learn/courses/30/lessons/42748
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++) {
        int from = commands[i][0];
        int to = commands[i][1];
        int selected = commands[i][2];
        
        vector<int> temp = array;
        sort(temp.begin() + from - 1, temp.begin() + to); // 끊어서 정렬 시키기

        answer.push_back(temp[from - 1 + selected - 1]);
    }
    
    return answer;
}
