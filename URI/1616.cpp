#include <bits/stdc++.h>

using namespace std;
int n,m;
#define INF 0x3F3F3F3F

int pd[15][(1 << 15)][6];
int g[15][15];
int f(int i, int mask, int k){
  if((1 << n) - 1 == mask){
    return 0;
  }
  if(k < 0){
    return INF;
  }
  if(pd[i][mask][k] != -1) {
    return pd[i][mask][k];
  }
  
  int ans = INF;
  for(int j = 0; j < n; j++){
    if((1 << j) & mask){
      continue;
    } 
    if(k > 0){
      ans = min(ans, f(j, (1 << j) | mask, k - 1));
    }
    ans = min(ans, f(j, (1 << j) | mask, k) + g[i][j]);
  }
  return pd[i][mask][k] = ans;
}

int main(){

  int k, t;
  
  scanf("%d",&t);
  
  while(t--){
    
    scanf("%d %d %d",&n,&m,&k);
    
    
    memset(g,INF,sizeof g);
    for(int i = 0; i < m; ++i){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      a--; b--;
      if(c < g[a][b]){
        g[a][b] = g[b][a] = c;
      }
    }
    if(n <= k){
      printf("0\n");
      continue;
    }
    memset(pd,-1,sizeof pd);

    for(int i = 0; i < n; i++){
      g[i][i] = 0;
    }
    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    int ans = f(0,0,k);
    printf("%d\n", ans == INF ? -1 : ans);
    
  }
  
  return 0;
}
