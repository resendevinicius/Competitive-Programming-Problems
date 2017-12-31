#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int n;
  while(scanf("%d",&n), n){
    printf("Printing order for %d pages:\n", n);
    int a = n;
    int sz = n / 4;
    if(sz * 4 < n) sz++;
    int skp = sz * 4 - n;
    int p = 0;
    bool front = 1;
    int b = skp + 1;
    for(int i = 0; i < (sz << 1); i++){
      if(i < skp){
        if(front){
          printf("Sheet %d, front: Blank, %d\n", ++p,i + 1);
        } else {
          if(i + 1 <= n){
            printf("Sheet %d, back : %d, Blank\n", p, i + 1);
          }
        }
      } else {
        if(front){
          printf("Sheet %d, front: %d, %d\n", ++p, a, b);
          a--; b++;
        } else {
          printf("Sheet %d, back : %d, %d\n", p, b, a);
          a--; b++;
        }
      }
      front = !front;
    }
  }
  
  return 0;
}
