#include <iostream>
using namespace std;

int arr_a[600][600];

int main(void){
  int h, w, x, y;
  cin >> h >> w >> x >> y;

  for(int i = 0; i < (h + x); i++){
    for(int j = 0; j < (w + y); j++){
      int v;
      cin >> v;
      
      // 겹치는 부분
      if(i >= x && i < h && j >= y && j < w){
        arr_a[i][j] = v - arr_a[i - x][j - y];
      }
      else{ // 안겹치는 부분
        arr_a[i][j] = v;
      }
    }
  }

  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout<<arr_a[i][j]<<' ';
    }
    cout<<'\n';
  }
}
