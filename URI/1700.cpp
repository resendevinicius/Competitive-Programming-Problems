//@Author: Vinícius Resende. 07/12/2017 - 21:03:44
#include <bits/stdc++.h>

using namespace std;
int n;

#define N 100001
int dp[2][N * 2];
int MAX;
int v[N];
#define INF 0x3F3F3F3F
int main(){
  while(scanf("%d",&n), n){
    MAX = 0;
    for (int i = 0; i < n; i++){
      scanf("%d",&v[i]);
      MAX += v[i];
    }
    MAX >>= 1;
    memset(dp, -INF, sizeof dp);
    dp[n & 1][N] = 0;
    for(int i = n - 1; i >= 0; i--){
      dp[i & 1][N] = 0;
      for(int j = MAX; j >= -MAX; j--){
        dp[i & 1][j + N] = dp[~i & 1][j + N];
        dp[i & 1][j + N] = max(dp[i & 1][j + N], dp[~i & 1][j + N + v[i]] + v[i]);
        dp[i & 1][j + N] = max(dp[i & 1][j + N], dp[~i & 1][j + N - v[i]]);
      }
    }
    printf("%d\n", dp[0][N]);
  }
  return 0;
}
