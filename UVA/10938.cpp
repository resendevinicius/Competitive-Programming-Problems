  #include <bits/stdc++.h>

  using namespace std;

  const int N = 5e3 + 10;
  const int LOG = 14;
  vector<int> g[N];
  int L[N];
  int p[N][LOG];
  int cost[N];
  void dfs(int x, int dad){
    p[x][0] = dad;
    L[x] = L[dad] + 1;
    for(int i = 1; i < LOG; i++){
      p[x][i] = p[p[x][i - 1]][i - 1];
    }
    
    for(auto u: g[x]){
      if(u == dad) continue;
      dfs(u, x);
    }
  }

  int solve(int x, int y){
    for(int i = LOG - 1; i >= 0; i--){
      if(L[x] - (1 << i) >= L[y]){
        x = p[x][i];
      }
    }
    if(x == y){
      return x;
    }
    for(int i = LOG - 1; i >= 0; i--){
      if(p[x][i] != p[y][i]){
        x = p[x][i];
        y = p[y][i];
      }
    }
    return p[x][0];
  }

  int main(){
    
    int n;
    while(scanf("%d",&n), n){
      int a,b;
      for(int i = 0; i < n - 1; i++){
        scanf("%d %d",&a,&b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
      }
      L[0] = -1;
      dfs(0, 0);
      int m;
      scanf("%d",&m);
      
      while(m--){
        scanf("%d %d",&a,&b);
        a--; b--;
        if(L[a] < L[b]){
          swap(a, b);
        }
        int lca = solve(a,b);
        int dist = L[a] + L[b] - L[lca] * 2;
        
        if(!(dist & 1)){
          dist >>= 1;
          for(int i = LOG - 1; i >= 0; i--){
            if(dist - (1 << i) >= 0){
              a = p[a][i];
              dist -= (1 << i);
            }
          }
          printf("The fleas meet at %d.\n", a + 1);
          
        } else {
          dist >>= 1;
          for(int i = LOG - 1; i >= 0; i--){
            if(dist - (1 << i) >= 0){
              a = p[a][i];
              dist -= (1 << i);
            }
          }
          printf("The fleas jump forever between %d and %d.\n", min(p[a][0] + 1, a + 1), max(a + 1, p[a][0] + 1));
        }
      }
      for(int i = 0; i < n; i++) g[i].clear();
    }
    
    
    return 0;
  }
