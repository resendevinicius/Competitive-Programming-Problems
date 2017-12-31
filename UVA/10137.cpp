#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  
  while(scanf("%d",&n), n){
    double v[n];
    double sum = 0.;
    for(int i = 0; i < n; i++){
      scanf("%lf",&v[i]);
      sum += v[i];
    }
    sum /= n;
    double neg = 0;
    double pos = 0;
    for(int i = 0; i < n; i++){
      (v[i] - sum >= 0.) ? pos += ((long) ((v[i] - sum) * 100.)) / 100. : neg += ((long) ((v[i] - sum) * 100.)) / 100. ;
    }
    printf("$%.2lf\n", pos >= -neg ? pos : -neg);
  }
  
  return 0;
}
