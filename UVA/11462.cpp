#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int v[N];
int n;
int main(){
  
  while(scanf("%d",&n), n){
    memset(v, 0, sizeof v);
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d",&x);
      v[x]++;
    }
    bool ok = false;
    for(int i = 0; i <= 100; i++){
      while(v[i]--){
        if(ok) printf(" ");
        printf("%d", i);
        ok = true;
      }
    }
    puts("");
  }
  
  return 0;
}
