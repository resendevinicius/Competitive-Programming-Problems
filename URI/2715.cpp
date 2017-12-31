//@Author: Vinícius Resende. 03/12/2017 - 22:33:44
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e6 + 10;
ll v[N];
int main(){
  
  ll n;
  while(scanf("%lld",&n) != EOF){
    ll sum = 0LL;
    for(int i = 0; i < n; i++){
      scanf("%lld",&v[i]);
      sum += v[i];
    }
    ll tmp = 0ll;
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
      sum -= v[i];
      tmp += v[i];
      ans = min(ans, llabs(sum - tmp));
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
