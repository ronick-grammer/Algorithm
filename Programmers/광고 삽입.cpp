#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
using namespace std;

//problem link: https://programmers.co.kr/learn/courses/30/lessons/72414

int all_time[360000]; // 최대 구간

vector<string> splitStringByCharacter(string str, char c){
    vector<string> splitedStrings; 
    istringstream iss(str);

    string token;
    while(getline(iss, token, c)){ // c 문자를 기준으로 문자열이 나누어진다
        splitedStrings.push_back(token);
    }

    return splitedStrings;
}

int hoursToSeconds(const vector<string>& hour){
  int seconds;
  int s_hour, s_min, s_sec;

  s_hour = stoi(hour[0]) * 3600;
  s_min = stoi(hour[1]) * 60;
  s_sec = stoi(hour[2]);

  seconds = s_hour + s_min + s_sec;

  return seconds;
}

string secondsToTimeString(int seconds){
  string timeString;
  string hour, min, sec;

  int time = seconds / 3600;
  hour = (time < 10) ? ("0" + to_string(time)) : to_string(time);

  time = (seconds % 3600) / 60;
  min = (time < 10) ? ("0" + to_string(time)) : to_string(time);

  time = (seconds % 3600) % 60;
  sec = (time < 10) ? ("0" + to_string(time)) : to_string(time);
  
  timeString = hour + ":" + min + ":" + sec;

  return timeString;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
  
    for(int i = 0; i < logs.size(); i++){
      vector<string> log_start_n_end_time = splitStringByCharacter(logs[i], '-');
      vector<string> sep_start_time = splitStringByCharacter(log_start_n_end_time[0], ':');
      vector<string> sep_end_time = splitStringByCharacter(log_start_n_end_time[1], ':');

      int start_sec_log = hoursToSeconds(sep_start_time); // 시청자가 동영상을 보기 시작하는 시간
      int end_sec_log = hoursToSeconds(sep_end_time); // 시청자가 동영상을 보기를 끝내는 시간
      
      for(int j = start_sec_log; j < end_sec_log; j++){ // 시청자 수 누적
        all_time[j]++;
      }
    }

    vector<string> sep_play_time = splitStringByCharacter(play_time, ':');
    vector<string> sep_adv_time = splitStringByCharacter(adv_time, ':');

    int length_play_time, length_adv_time;
    length_play_time = hoursToSeconds(sep_play_time);
    length_adv_time = hoursToSeconds(sep_adv_time);

    // *참고: 시청자 수는 최대 300,000 명이다.
    // 만약에 동영상 길이가 최대 360,000 초인데 이 모든 구간을 동시간대에 최대 시청자 수인 300,000이 시청한다고 가정해 보자.
    // 그러니까 동영상 시작 부터 360,000 초 동안 300,000 명의 사람들이 시청한다고 가정해 보는 것이다.
    // 한 구간(초) 마다 300,000 명의 사람들이 시청하는 것이니까. 광고 시간 역시 360,000 초로 동영상 시간과 동일하다면 
    // 광고 시간의 구간합은 300,000 * 360,000 = 108,000,000,000 이 되는 것이다.
    // int 형의 범위는 –2,147,483,648 ~ 2,147,483,647 이므로 이 최대 값을 담을 수가 없다.
    // 그렇기에 –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 범위를 가지는 long long 형으로 선언해서
    // 합을 구해주어야만 정답 처리를 받을 수가 있다.
    long long sum = 0, maxSum = 0;
    for(int i = 0; i < length_adv_time; i++){
      maxSum += all_time[i];
    }
    
    sum = maxSum;
    int startTime = 0;
    for(int i = length_adv_time; i < length_play_time; i++){
      // 광고 재생 시작 시간을 1초씩 옯긴다. 그리고 옯겼을 때의 구간 합을 새로 구한다.
      sum = (sum - all_time[i - length_adv_time]) + all_time[i];

      // 1초 옮긴 광고의 재생 구간 합이 기존 구간 합보다 높으면 새로 갱신
      // 즉, 1초 옮긴 광고 재생 구간에서 시청자 수가 많으면 새로 최대 시청자수 갱신
      if(maxSum < sum){
        maxSum = sum;
        startTime = i - length_adv_time + 1;
      }
    }

    answer = secondsToTimeString(startTime);
    return answer;
}
