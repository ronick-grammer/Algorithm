#include <iostream>
using namespace std;

//problem link; https://www.acmicpc.net/problem/1244

int size_switch;
int size_students;
bool switches[101];

int main(void){
  cin>>size_switch;
  for(int i = 1; i <= size_switch; i++){
    cin >> switches[i];
  }
  cin>>size_students;
  for(int i = 0; i < size_students; i++){
    int gender;
    int number;
    cin >> gender >> number;

    if(gender == 1){ // 남학생이면
      for(int j = number; j <= size_switch; j += number){ // 배수에 위치한 스위치를 반대 값으로
        switches[j] = !switches[j];
      }
    }
    else{ // 여학생이면
      switches[number] = !switches[number]; // 기준에 위치한 스위치를 바꾸고
      int left = number - 1; 
      int right = number + 1;
      // 그 중심으로 양 옆에 있는 스위치를 확인하여 양 옆 스위치의 값이 같으면 반대의 값으로 계속 갱신해 준다
      while(left >= 1 && right <= size_switch){
        if(switches[left] == switches[right]){
          switches[left] = !switches[left];
          switches[right] = !switches[right];
          left--;
          right++;
        }
        else{
          break;
        }
      }
    }
  }

  for(int i = 1; i <= size_switch; i++){
    cout<<switches[i]<<' ';
  
    if(i % 20 == 0){
      cout<<'\n';
    }
  }
}
