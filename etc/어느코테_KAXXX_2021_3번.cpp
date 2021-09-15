#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int carSeconds[10000];
int inSeconds[10000];
bool carIn[10000]; // 주차장에 들어왔으면 true

int timeStringToMinutes(string timeString) { // 시간 문자열을 분 단위로 변환하기
    int hour = stoi(timeString.substr(0, 2));
    int min = stoi(timeString.substr(3, 2));

    int mins = hour * 60;
    mins += min;

    return mins;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int fixedMin = fees[0];
    int fixedFee = fees[1];
    int unitMin = fees[2];
    int unitFee = fees[3];

    vector<int> carNumbers;
    for(int i = 0; i < records.size(); i++) {
        int timeSeconds = timeStringToMinutes(records[i].substr(0, 5));
        int carNumber = stoi(records[i].substr(6, 4));
        string InOut = records[i].substr(11);

        if(InOut == "IN"){ // 주차장에 들어왔으면
            inSeconds[carNumber] = timeSeconds; // 들어온 시간 저장
            carIn[carNumber] = true; // 들어왔다는 처리로 true
        } else { // "OUT" 이면
            carSeconds[carNumber] += timeSeconds - inSeconds[carNumber]; // 주차한 시간을 누적해서 총합 구하기
            inSeconds[carNumber] = 0; // 들어온 시간은 다시 초기화
            carIn[carNumber] = false; // 주차장에서 나갔으니 false
        }
    }

    // 9999대의 차 중에서 주차장에 들어오기만 하고 나가지 않은 차가 있으면 23:59 까지 주차한 걸로 하고 머문 시간 누적하기
    for(int i = 0; i <= 9999; i++) {
        if(carIn[i]) {
            carSeconds[i] += timeStringToMinutes("23:59") - inSeconds[i];
        }
    }

    // 각 차들의 주차요금 계산하기
    for(int i = 0; i <= 9999; i++) {
        if(carSeconds[i] != 0) {
            int a;
            int fee;
            
            // 총 주차시간이 고정 주차시간보다 적으면 그냥 고정 요금으로 계산하기
            if((carSeconds[i] - fixedMin) <= 0)
                fee = fixedFee;
            else {
                a = (carSeconds[i] - fixedMin) / unitMin;
                
                // 반올림 시키기
                if(a < 1) 
                    a = 1;
                else if((carSeconds[i] - fixedMin) % unitMin != 0)
                    a++;

                fee = fixedFee + a * unitFee;
            }

            answer.push_back(fee);
        }
    }

    return answer;
}
