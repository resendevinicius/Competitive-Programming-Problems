#include <bits/stdc++.h>

using namespace std;
int a[222][222];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    memset(a,0,sizeof a);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> a[i][j];
        a[i + n][j] = a[i][j + n] = a[i][j];
      }
    }
    for(int i = 0; i < (n << 1); i++){
      for(int j = 0; j < (n << 1); ++j){
        if(i) a[i][j] += a[i - 1][j];
        if(j) a[i][j] += a[i][j - 1];
        if(i && j) a[i][j] -= a[i - 1][j - 1];
      }
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        for(int k = i; k < i + n; k++){
          for(int l = j; l < j + n; l++){
            int tmp = a[k][l];
            if(i) tmp -= a[i - 1][l];
            if(j) tmp -= a[k][j - 1];
            if(i && j) tmp += a[i - 1][j - 1];
            ans = max(ans, tmp);
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
