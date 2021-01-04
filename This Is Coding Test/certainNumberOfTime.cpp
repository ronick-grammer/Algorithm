#include <iostream>
using namespace std;

int main(void){
    int n;
    int result = 0;
    cin>>n;

    for(int i = 0; i <= n; i++){ // hours
        for(int j = 0; j <= 59; j++){ // mins
            for(int k = 0; k <= 59; k++){ // seconds
                // 3이 포함되는 경우의 수를 구한다
                if(i % 10 == 3 || j / 10 == 3 || k / 10 == 3 || j % 10 == 3 || k % 10 == 3){
                    result++;
                }
            }
        }
    }

    cout<<result<<endl;
}
