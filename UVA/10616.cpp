#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
#define int long long
int v[N];
int d, m;
int n,q;
int pd[N][11][21];
int f(int i, int j, int sum){
  if(i == n || j == m){
    if(j == m){
      return sum == 0;
    }
    return 0;
  }
  if(pd[i][j][sum] != -1) return pd[i][j][sum];
  int ans = f(i + 1, j, sum) + f(i + 1, j + 1, ((sum + v[i]) % d + d)% d);
  return pd[i][j][sum] = ans;
}
int32_t main(){
  int caso = 0;
  while(scanf("%lld %lld",&n,&q) , n | q){
    
    printf("SET %lld:\n", ++caso);
    for(int i = 0; i < n; i++){
      scanf("%lld", v + i);
    }
    for(int i = 1; i <= q; i++) {
      scanf("%lld %lld",&d,&m);
      memset(pd,-1,sizeof pd);
      printf("QUERY %lld: %lld\n", i, f(0,0,0));
    }
    
  }
  return 0;
}
