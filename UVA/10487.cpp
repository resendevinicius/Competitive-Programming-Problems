#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int ans[N];
int v[N];
int main(){
  int n;
  int caso = 0;
  while(scanf("%d",&n), n){
    
    for(int i = 0; i < n; i++){
      scanf("%d",v + i);
    }
    
    int k = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i == j) continue;
        ans[k++] = v[i] + v[j];
      }
    }  
    sort(ans, ans + k);
    int q;
    scanf("%d",&q);
    printf("Case %d:\n", ++caso);
    while(q--){
      int x;
      scanf("%d",&x);
      int dif = INT_MAX;
      int resp = 0;
      for(int i = 0; i < k; i++){
        if(abs(ans[i] - x) < dif){
          resp = ans[i];
          dif = abs(ans[i] - x);
        }
      }
      printf("Closest sum to %d is %d.\n", x, resp);
    }
  }
  
  return 0;
}
