//@Author: Vinícius Resende. 03/12/2017 - 23:15:05
#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 150;
int dp[2][N * 2001];
int v[N];
int sum;
int main(){
  while(scanf("%d",&n) != EOF){
    sum = 0;
    for(int i = 0; i < n; i++){
      scanf("%d",&v[i]);
      sum += v[i];
    }
    memset(dp,0,sizeof dp);
    for(int i = n - 1; i >= 0; i--){
      for(int j = (sum >> 1); j >= 0; j--){
        dp[i & 1][j] = max(dp[~i & 1][j], dp[i & 1][j]);
        if(j + v[i] <= (sum >> 1)){
          dp[i & 1][j] = max(dp[i & 1][j], dp[~i & 1][j + v[i]] + v[i]);
        } 
      }
    }
    printf("%d\n", sum - (dp[0][0] << 1));
  }
  
  return 0;
}
