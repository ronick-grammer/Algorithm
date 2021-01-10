#include <iostream>
using namespace std;

int n, m, result;
int arr[1001];

int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr[k]++; // 각 무게의 볼링공 갯수 저장
    }

    for(int i = 1; i <= m; i++){ // a가 무게가 낮은 볼링공부터 선택했을 경우를 기준으로 
        n -= arr[i]; // 해당 무게의 볼링공의 수를 빼주고(a가 해당 무게의 볼링공을 잡은경우)
        result += arr[i] * n; // 나머지 무게들의 볼링공 수만큼 곱해준다 (b가 나머지 무게들의 볼링공들을 잡는 경우)
    }

    cout<<result<<endl;
}
