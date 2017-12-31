#include <bits/stdc++.h>

using namespace std;
#define INF 0x3F3F3F3F
const int N = 1e5 + 10;
int dir[N], esq[N];

int main(){
  
  int s,b;
  
  while(scanf("%d %d",&s,&b), s | b){
    for(int i = 1; i <= s; i++){
      dir[i] = i + 1;
      esq[i] = i - 1;
    }    
    esq[1] = -1;
    dir[s] = -1;
    while(b--) {
      int l, r;
      scanf("%d %d",&l,&r);
      esq[dir[r]] = esq[l];
      dir[esq[l]] = dir[r];
      if(esq[l] == -1){
        printf("* ");
      } else {
        printf("%d ", esq[l]);
      }
      if(dir[r] == -1){
        printf("*\n");
      } else {
        printf("%d\n", dir[r]);
      }
    }
    puts("-");
  }
  
  
  return 0;
}
