//@Author: Vinícius Resende. 07/12/2017 - 19:56:47


#include <bits/stdc++.h>

using namespace std;
int n, c;
const int N = 2e5 + 10;
int v[N];
int dp[N][2];
// 1 nao peguei
// 0 peguei
int f(int i, bool peguei){
  if(i == n) return 0;
  if(dp[i][peguei] != -1) return dp[i][peguei];
  int ans = f(i + 1, 1);
  if(i) ans = max(ans, f(i + 1, 0) + v[i] - v[i - 1] - peguei * c);
 
  return dp[i][peguei] = ans;
}
int main(){
  scanf("%d %d",&n, &c);
  
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0,1));
  return 0;
}
