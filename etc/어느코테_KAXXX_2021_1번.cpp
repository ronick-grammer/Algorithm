#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> reported_cnt; // 각 유저의 신고당한 횟수
map<string, vector<bool> > reported_reportIndex; // 신고당한 유저, 신고한 유저들의 인덱스
map<string, int> user_index; // 각 유저의 인덱스

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    for(int i = 0; i < id_list.size(); i++) {
        user_index.insert(make_pair(id_list[i], i));
        reported_cnt.insert(make_pair(id_list[i], 0));

        vector<bool> reportIndex(id_list.size(), false);
        reported_reportIndex.insert(make_pair(id_list[i], reportIndex));
        
    }
    
    for(int i = 0; i < report.size(); i++) {
        int spaceIndex = report[i].find(" ");
        string user_report =  report[i].substr(0, spaceIndex);
        string user_reported = report[i].substr(spaceIndex + 1);

        if(!reported_reportIndex[user_reported][user_index[user_report]]){ // 한 유저에게 처음 신고당한 것이라면
            reported_cnt[user_reported]++; // 신고 횟수 증가
            reported_reportIndex[user_reported][user_index[user_report]] = true; // 중복 신고 불가능
        }
    }

    for(int i = 0; i < id_list.size(); i++) {
        string reported = id_list[i];
        if(reported_cnt[reported] >= k) { // k번 이상으로 신고당한 유저라면
            for(int j = 0; j < reported_reportIndex[reported].size(); j++) {
                if(reported_reportIndex[reported][j]) // 그 유저를 신고한 유저들에게 알리기
                    answer[j]++;
            }
        }
    }
    
    return answer;
}
