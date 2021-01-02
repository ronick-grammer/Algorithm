#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int inDegree[501]; // 각 강의들의 진입차수 
int lectureTime[501]; // 각 강의들의 시간 (정적)
int min_lectureTime[501]; // 각 강의들의 선수과목을 고려했을때의 최소 수강시간 (동적)
vector<int> graph[501]; // 각 강의들의 선수과목 그래프
queue<int> q;

void tropologySort(){
    for(int i = 1; i <= n; i++){ // 진입차수가 하나도 없는(선수과목이 하나도 없는) 강의부터 시작
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int prev = q.front();
        q.pop();

        for(int i = 0; i < graph[prev].size(); i++){ // 선수 과목다음 들을 수 있는 강의 수만큼 진행
            int current = graph[prev][i]; // 선수과목의 다음 강의를 하나씩 꺼낸다
            inDegree[current]--; // 진입차수 감소

            // 선수 강의를 듣고 현재 강의를 들었을때의 최소 시간을 기록
            min_lectureTime[current] = max(
                min_lectureTime[current], 
                lectureTime[current] + min_lectureTime[prev]); 

            if(inDegree[current] == 0){ // 더이상의 선수강의가 없으면 
                q.push(current); 
            }
        }
    }
}

int main(void){
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>lectureTime[i]; // 시간을 입력
        min_lectureTime[i] = lectureTime[i]; 
        for(int j = 0; j < n - 1; j++){ // 현재 강의를 제외한 수만큼 입력 가능
            int input;
            cin >> input;

            if(input == -1){ // -1 이면 다음 강의에 대한 시간과 선수과목들을 입력
                break;
            }
            else{ // 선수과목 그래프와 진입 차수 처리
                graph[input].push_back(i); 
                inDegree[i]++;
            }
        }
    }

    tropologySort();

    for(int i = 1; i <= n; i++){
        cout<<min_lectureTime[i]<<endl;
    }
}
