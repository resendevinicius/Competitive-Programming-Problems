#include <bits/stdc++.h>


using namespace std;

int main(){
  
  int mes, n;
  double parcela, carro;
  
  while(scanf("%d %lf %lf %d",&mes, &parcela, &carro, &n), mes > 0){
    double v[111];
    double total = carro;
    carro += parcela;
    parcela = total / mes;
    while(n--) {
      int j;
      double val;
      scanf("%d %lf", &j,&val);
      for(int k = j; k < 101; k++) v[k] = val;
    }
    int ans = 0;
    carro -= carro * v[0];
    
    while(carro < total){
      ans++;
      carro *= (1 - v[ans]);
      total -= parcela;
    }
    ans == 1 ? printf("1 month\n") : printf("%d months\n", ans);
  }
  
  return 0;
}
