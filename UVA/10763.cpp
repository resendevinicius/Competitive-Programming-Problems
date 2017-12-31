#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main(){
  
  
  int n;
  while(scanf("%lld",&n), n){
    vector<int> x, y;
    for(int i = 0; i < n; i++){
      int a,b;
      scanf("%d %d",&a,&b);
      x.push_back(a);
      y.push_back(b);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    puts(x == y ? "YES" : "NO" );
  }
  
  return 0;
}
