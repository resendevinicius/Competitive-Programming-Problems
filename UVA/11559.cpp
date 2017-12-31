#include <bits/stdc++.h>
//@Author: Vinícius Resende. 23/11/2017 - 01:39:25

using namespace std;
#define int long long

int32_t main(){
  int n,b,h,w;
  while(scanf("%lld %lld %lld %lld",&n,&b,&h,&w) != EOF){
    int ans = LLONG_MAX;
    for(int i = 0; i < h; i++){
      int p;
      scanf("%lld",&p);
      int people = 0;
      for(int j = 0; j < w; j++){
        int x;
        scanf("%lld",&x);
        people = max(people, x);
      }
      if(people >= n){
        ans = min(ans, n * p);
      }
    }
    ans > b ? printf("stay home\n") : printf("%lld\n", ans);
  }
  
  
  return 0;
}
