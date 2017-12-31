#include <bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u;
double check(double x){
  return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x) + u);
}

int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(4);
  while(cin >> p >> q >> r >> s >> t >> u){
    double hi = 1;
    double lo = 0;
    for(int i = 0; i < 100; i++){
      double mid = lo + (hi - lo) * 0.5;
      double ans = check(mid);
      if(ans < 0){
        hi = mid;
      } else {
        lo = mid;
      } 
    }
    double answer = check(lo);
    if(fabs(answer) < 1e-5){
      cout << lo << endl;
    } else {
      cout << "No solution" << endl;
    }
  }
  
  return 0;
}
