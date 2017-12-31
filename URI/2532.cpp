#include <bits/stdc++.h>

using namespace std;

int n, p;

const int N = 1e3 + 10;

int pd[N][N * 2];
int d[N], m[N];

#define INF 0X3F3F3F3F
int f(int i, int j){
  if(j <= 0){
    return 0;
  }
  if(i == n){
    return INF;
  }
  if(pd[i][j] != -1){
    return pd[i][j];
  }
  
  int ans = f(i + 1, j);
  ans = min(ans,f(i + 1, j - d[i]) + m[i]);
  
  return pd[i][j] = ans;
}

int main()
{
  
  
  while(scanf("%d %d",&n,&p) != EOF){
    int ok = 0;
    for(int i = 0; i < n; i++){
      scanf("%d %d",&d[i],&m[i]);
      ok += d[i];
    }
    if(ok < p){
      puts("-1");
    } else {
      memset(pd,-1,sizeof pd);
      printf("%d\n", f(0,p));
    }
  }
  
  return 0;
}
