#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
  int n, s;
  
  while(scanf("%d %d",&n, &s) != EOF){
    int v[n];
    
    for(int i = 0; i < n; i++){
      scanf("%lld",&v[i]);
    }
    
    int j = 0, i = 0;
    ll sum = 0;
    int ans = INT_MAX;
    bool OK = false;
    while(i < n && sum < s){
      bool ok = false;
      sum += v[i++];
      while(j < i && sum >= s){
        sum -= v[j++];
        ok = true;
        OK = true;
      }
      if(ok) ans = min(ans, i - j + 1);
    }
    printf("%d\n", !OK ? 0 : ans);
  }
  return 0;
}
