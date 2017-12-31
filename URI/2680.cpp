#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e4 + 10;
int p[N];
int v[N];
int idx = 0;
void crivo(){
  
  for(int i = 2; i < N; i++){
    if(!p[i]){
      for(int j = i; j < N; j += i){
        p[j] = 1;
      }
      v[idx++] = i;
    }
  }
}


int32_t main(){

  int n;
  
  crivo(); 
  scanf("%lld",&n);
  while(n--){
    int x;
    scanf("%lld",&x);
    int sum = 1;
    int i = 0;
    int PF = v[i];
    while(PF * PF <= x){
      int power = 0;
      while(x % PF == 0){
        x /= PF;
        power++;
      }
      sum *= ((int)pow((double)PF, power + 1.0) - 1) / (PF - 1);
      PF = v[++i];
    }
    if(x != 1){
      sum *= ((int) pow((double)x, 2.0) - 1) / (x - 1);
    }
    
    printf("%lld\n", sum);
  }
  
  
  return 0;
}
