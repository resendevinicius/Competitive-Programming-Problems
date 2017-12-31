#include <bits/stdc++.h>

using namespace std;
#define eps 1e-6
int n, ml;
int b, B, H;
double x;
int check(double h){
  double R = b + (((B - b) * h) / H);
  double v = ((M_PI * h) / 3.) * (R * R + R * b + b * b);
  
  if(fabs(v - x) < eps) return 1;
  else if(v > x) return 0;
  return 2;
}

int main(){
  cout << fixed << setprecision(2);
  int t;
  cin >> t;
  
  while(t--){
    cin >> n >> ml;
    cin >> b >> B >> H;
    
    x = ml / (double) n;
    double hi = 1e12;
    double lo = 0;
    for(int i = 0; i < 100; i++){
      double mid = lo + (hi - lo) / 2.;
      int k = check(mid);
      if(k == 1){
        cout << mid << endl;
        break;
      } else if(!k){
        hi = mid;
      } else {
        lo = mid;
      }
    }
  }
  
  
  return 0;
}
