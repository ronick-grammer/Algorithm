#include <iostream>
#include <algorithm>
using namespace std;

int n;
int steps[101]; // 발판의 다음 이동값
bool visited[101]; // 방문여부
int result;

int main(void){
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        int x; 
        cin >> x;
        steps[i] = x;
    }

    // 1번 발판, 2번 발판, 3번 발판을 시작으로 발판들을 밟은 최대 횟수를 저장.
    for(int i = 1; i <= 3; i++){ 
        int cnt = 2; // 처음에는 두 번 발판을 밟을수 있다
        int position = i + steps[i]; //첫 발판 위치에서 다음 발판 위치로 이동
        visited[i] = true; // 시작 발판은 방문처리

        while(!visited[position]){ // 한번도 밟지 않았던 발판이면 계속 진행
            visited[position] = true; // 발판 방문처리
            position += steps[position]; // 다음 발판으로 이동할 준비
            cnt++; // 밟은 발판들의 횟수
        }
        result = max(result, cnt); // 밟은 발판들의 최대 횟수
        fill_n(visited, 101, false); // 방문 여부 초기화
    }

    cout<<result<<'\n';
}
