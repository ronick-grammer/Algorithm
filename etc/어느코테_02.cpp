#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

#define NOMAL 0
#define HOLIDAY 1

//problem link: 비공개, 비밀이지롱


// 휴일을 포함한 달력을 저장하기 위해 일년 최대 12 개월, 각 월의 최대 일 수 31
// 13과 32는 인덱스로는 각각 [12] 와 [31] 까지 표현되기 때문
vector<vector<int> > calender(13, vector<int>(32, NOMAL));

// 각 월의 말일
int endOfEachMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 1월 [1] 일이 금요일이기 때문에, 인덱스 [1]은 금요일로 둔다. (총 경과 일 수 % 7) 의 값을 인덱스로 사용하기 위해서
string weekDays[7] = {"목", "금", "토", "일", "월", "화", "수"}; 
bool visited[366]; // 중복값 여부

bool compare(int a, int b){ // 내림 차순
    return a > b;
}

vector<string> splitString(string str, char c){
    vector<string> splitedStrings; 
    istringstream iss(str);

    string token;
    while(getline(iss, token, c)){ // c 문자를 기준으로 문자열이 나누어진다
        splitedStrings.push_back(token);
    }

    return splitedStrings;
}

int solution(vector<string> holidays, int k){
    int answer = 0;
    vector<pair<int, int> > holidays_month_day; // 각 휴일의 달과 일을 int 형으로 분리해서 담을 변수
    vector<int> successiveCounts; // 연속되는 휴일수를 저장할 변수
    
    for(int i = 0; i < holidays.size(); i++){ // month 와 day 분리
        vector<string> splitedString = splitString(holidays[i], '/');
        int month = stoi(splitedString[0]);
        int day = stoi(splitedString[1]);

        holidays_month_day.push_back(make_pair(month, day));
    }

    for(int i = 0; i < holidays_month_day.size(); i++){  // 휴가일만 지정
        int month = holidays_month_day[i].first;
        int day = holidays_month_day[i].second;
        calender[month][day] = HOLIDAY;
    }

    int sum_days = 0; // 총 경과 일
    int successiveCount = 0; // 연속되는 휴일 수
    for(int month = 1; month <= 12; month++){
        sum_days += endOfEachMonth[month - 1]; // 전 월끼지의 최대 일수를 계속해서 더해준다
        // 해당 월만 진행
        for(int day = sum_days + 1; day <= (sum_days + endOfEachMonth[month]); day++){
            
            // 해당 일이 휴일이거나 주말이면
            if(calender[month][day - sum_days] == HOLIDAY || weekDays[day % 7] == "토" || weekDays[day % 7] == "일"){
                successiveCount++; // 연속된 휴일 횟수 증가
            }
            else{ // 해당 일이 휴일이 아니라면
                if(successiveCount > 0){ // 그 전까지 연속되었던 휴일 연속횟수를 저장
                    if(!visited[successiveCount]){ // 다만 중복값 허용 x
                        successiveCounts.push_back(successiveCount);
                        visited[successiveCount] = true;
                    }
                    successiveCount = 0; // 다시 연속되는 휴일 수 초기화
                }
            }
        }
    }
    if(successiveCount >= 3){ // 휴일이 365 일 연속으로 있는 경우라면 
        successiveCounts.push_back(successiveCount);
    }

    sort(successiveCounts.begin(), successiveCounts.end(), compare); // 내림 차순
    answer = successiveCounts[k-1]; // k 번째로 큰 수
    return answer;
}

int main(void){
    vector<string> holidays;

    holidays.push_back("01/14");
    holidays.push_back("01/15");
    holidays.push_back("01/18");
    holidays.push_back("01/22");
    holidays.push_back("01/23");
    holidays.push_back("01/29");
    holidays.push_back("02/01");
    holidays.push_back("02/03");
    holidays.push_back("02/07");

    cout<<solution(holidays, 5);
}
