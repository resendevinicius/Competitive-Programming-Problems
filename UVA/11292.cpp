#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m;
    
    
  while(cin >> n >> m, n | m){
    int d[n];
    int k[m];
    for(int i = 0; i < n; i++){
      cin >> d[i];
    }
    for(int i = 0; i < m; i++){
      cin >> k[i];
    }
    sort(d, d + n);
    sort(k, k + m);
    int i, j;
    int ans = 0;
    for(i = 0, j = 0; i < n && j < m;){
      if(k[j] >= d[i]){
        ans += k[j];
        i++;
        j++;
      } else {
        j++;
      }
    }
    if(i == n){
      cout << ans << endl;
    } else {
      cout << "Loowater is doomed!" << endl;
    }
  }
  
  return 0;
}
