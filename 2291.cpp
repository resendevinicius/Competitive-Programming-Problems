#include <bits/stdc++.h>

using namespace std;


const int N = 1e6 + 10;
const int MAX = N / 2;
int primo[MAX];
int p[MAX];
int idx;
void crivo(){
  
  for(int i = 2; i <= MAX; i++){
    if(!primo[i]){
      for(int j = i; j <= MAX; j += i){
        primo[j] = 1;
      }
      p[idx++] = i;
    }
  }
}

double fastPow(int n, int e){
  
  if(e == 1){
    return n;
  }
  if((e & 1)){
    return n * fastPow(n, e - 1);
  } 
  double x = fastPow(n, e / 2);
  return x * x;
  
}

int main(){
  int n;
  
  crivo();
  long long ans[N];
  ans[0] = 0;
  ans[1] = 1;
  for(int i = 2; i <= N; i++){
    long sum = 1;
    int j = 0;
    int PF = p[j];
    int x = i;
    while(PF * PF <= x){
      int power = 0;
      while(x % PF == 0){
        x /= PF;
        power++;
      }
      sum *= (fastPow(PF, power + 1) - 1) / (PF - 1);
      PF = p[++j];
    }
    if(x != 1){
      sum *= (fastPow(x, 2) - 1) / (x - 1);
    }
    ans[i] = sum + ans[i - 1];
  }
  while(scanf("%d",&n), n){
    printf("%lld\n", ans[n]);
  }
  
  
  return 0;
}
