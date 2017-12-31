#include <bits/stdc++.h>
while(scanf("%d %d %d %d %d %d %d %d %d", &b[0],&b[1],&b[2],&g[0],&g[1],&g[2],&c[0],&c[1],&c[2]) == 9){
using namespace std;

#define int unsigned long long
int mod;
int fastExp(int x, int e){
  if(e == 0){
    return 1;
  }
  if(e & 1l){
    return (x * (fastExp(x, e - 1ul) % mod)) % mod;
  }
  int a = fastExp(x, e / 2ul) % mod;
  return (a * a) % mod;
}

int32_t main(){
  
  int a,b;
  
  while(scanf("%llu %llu %llu",&a,&b,&mod) != EOF){
    printf("%llu\n", fastExp(a % mod, b));
  }
  
  return 0;
}
