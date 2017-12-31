#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  int caso = 0;
  while(t--){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int freq[k + 5];
    memset(freq,0,sizeof freq);
    int v[n + 5];
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    if(k <= 3){
      printf("Case %d: %d\n", ++caso, k);
      continue;
    }
    for(int i = 4; i <= n; i++){
      v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % m + 1;
    }
    int i, j;
    i = j = 1;
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
      if(v[i] <= k){
        freq[v[i]]++;
      }
      bool ok = true;
      while(ok && j < i){
        for(int j = 1; j <= k; j++){
          if(!freq[j]) {
            ok = false;
            break;
          }
        }
        if(ok){
          ans = min(ans, i - j + 1);
          if(v[j] <= k){
            freq[v[j]]--;
          }
          j++;
        }
      }
    }
    printf("Case %d: ", ++caso);
    if(ans != INT_MAX){
      printf("%d\n", ans);
    } else {
      printf("sequence nai\n");
    }
  }
  
  return 0;
}
