#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int students[501][501];

int main(void){
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill_n(students[i], 501, INF);
    }

    for(int i = 1; i  <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                students[i][j] = 0; // 자기 자신은 0을 삽입
            }
        }
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        students[a][b] = 1; // A 번 학생이 B 번 학생 보다 낮으면 1을 삽입
    }

    // A번 학생이 B번 학생을 직접 가르키는 경우외에도 다른 학생을 거쳐 간접적으로 가르키는 경우를 위해
    // 플로이드 와샬 진행, n이 500 이므로 O(N^3) 로 진행해도 큰 무리가 없다
    for(int through = 1; through <= n; through++){
        for(int from = 1; from <= n; from++){
            for(int to = 1; to <= n; to++){
                students[from][to] = min(students[from][to], students[from][through] + students[through][to]);
            }
        }
    }

    int count, result = 0;
    for(int i = 1; i <= n; i++){ // A번 학생과
        count = 0;
        for(int j = 1; j <= n; j++){  // 다른 학생들의 순위 비교가 되는지 확인
            // A번 학생 -> B번 학생 or B번 학생 -> A번 학생 일 경우 두 학생간의 비교가 가능하다는 것이다
            // 참고로 A번 학생 -> A번 학생도 비교횟수로 포함한다
            if(students[i][j] != INF || students[j][i] != INF){
                count++; // 그러므로 비교된 학생 수를 증가 해준다.
            }
        }
        if(count == n){ // 그렇게 A번 학생과 모든 학생이 순위 비교가 가능하다면
            result++; // A번 학생은 정확한 순위를 가지므로 그에 대한 횟수를 증가시킨다
        }
    }

    cout<<result<<'\n';
}
