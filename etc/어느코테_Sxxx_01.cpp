#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > reservation; // pc 번호, 사용 시간
int pc[101]; // 각 pc 들의 최대 이익
int hoursPerPC[101]; // 각 pc 들이 사용된 시간

int main(void){
    int pcs, users, hours; // pc 수, 예약자 수, 하루 운영 시간
    cin >> pcs >> users >> hours;

    for(int i = 0; i < users; i++){ // 예약
        int pcNumber, useHours;
        cin >> pcNumber >> useHours;
        reservation.push_back(make_pair(pcNumber, useHours));
    }

    for(int i = 0; i < users; i++){
        if(reservation[i].second + hoursPerPC[reservation[i].first] <= hours){ // 각 pc들이 사용된 총 시간 <= 하루 운영시간
            pc[reservation[i].first] += (1000 * reservation[i].second); // 해당 번호의 pc의 이익을 더해준다
            hoursPerPC[reservation[i].first] +=  reservation[i].second; // 해당 번호의 pc 사용시간을 더해준다.
        }
    }

    for(int i = 1; i <= pcs; i++){
        cout<<i<<' '<<pc[i]<<'\n';
    }
}
