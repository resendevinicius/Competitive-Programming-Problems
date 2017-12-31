//@Author: Vinícius Resende. 21/12/2017 - 13:14:27
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
long long dp[3][N];
int v[N];
int n;
int main(){  
  ios_base::sync_with_stdio(0); cin.tie(0);
  while(cin >> n){
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    for(int len = 1; len <= n; len++){
      for(int i = 0; i + len - 1 < n; i++){
        int j = i + len - 1;
        if(len == 1){
          dp[len][i] = v[i];
        } else if(len == 2){
          dp[len][i] = max(v[i], v[j]);
        } else {
          dp[len % 3][i] = max(v[i] + max(dp[(len - 2) % 3][i + 2], dp[(len - 2) % 3][i + 1]), v[j]
          + max(dp[(len - 2) % 3][i + 1], dp[(len - 2) % 3][i]));
        }
      }
    }
    cout << dp[n % 3][0] << endl;
  }
  return 0;
}
