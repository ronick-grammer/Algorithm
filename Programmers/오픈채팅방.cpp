//problem link: https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

map<string, string> id_nickname;
vector< pair<string, string> > newQuery;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i = 0; i < record.size(); i++) {
        string query = record[i];
        string type = "";
        string id = "";
        string nickname = "";
        
        int from = 0;
        int to = 0;
        
        // 메시지 종류
        to = query.find(" ", from);
        type = query.substr(from, to);
        from = to + 1;
        
        // 아이디
        to = query.find(" ", from);
        id = query.substr(from, to - from);
        from = to + 1;
        
        // 닉네임
        to = query.find(" ", from);
        nickname = query.substr(from, to - from);
        
        // 들어왔거나 아이디 변경했을 경우에 id의 닉네임을 바꿔줌
        if(type == "Enter" || type == "Change") {
            id_nickname[id] = nickname;
        }
        
        // 들어오거나 나갔을 경우에만 메시지들을 기록함
        if(type == "Enter" || type == "Leave") {
            newQuery.push_back(make_pair(id, type));
        }
        
    }
    
    // 해석하기 - 마지막에 남은 각 id의 닉네임으로 메시지들의 일치하는 각
    // id를 전부 바꿔주면 됨
    for(int i = 0; i < newQuery.size(); i++) {
        string nickname = id_nickname[newQuery[i].first];
        string type = "";
        
        if (newQuery[i].second == "Enter") {
            type = "님이 들어왔습니다.";
        } 
        else if(newQuery[i].second == "Leave") {
            type = "님이 나갔습니다.";
        }

        answer.push_back(nickname + type);
    }
    
    return answer;
}
