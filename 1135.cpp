#include <bits/stdc++.h>


using namespace std;
int n;
const int N = 2e5 + 10;
typedef long long ll;
vector<pair<int,ll> > g[N];
const int LOG = 18;
int p[N][LOG];
int L[N];
ll cost[N];
void dfs(int x, int dad, ll c){
  
  p[x][0] = dad;
  if(dad != -1){
    L[x] = L[dad] + 1;
  }
  cost[x] = c;
  for(int i = 1; i < LOG; i++){
    if(p[x][i - 1] != -1){
      p[x][i] = p[p[x][i - 1]][i - 1];
    }
  }
  for(auto u: g[x]){
    if(u.first != dad){
      dfs(u.first, x, c + u.second);
    }
  }
}

int lca(int x, int y){
  
  if(L[x] < L[y]){
    swap(x, y);
  }
  for(int i = LOG - 1; i >= 0; i--){
    if(p[x][i] != -1 && L[p[x][i]] >= L[y]){
      x = p[x][i];
    }
  }
  if(x == y) return x;
  for(int i = LOG - 1; i >= 0; i--){
    if(p[x][i] != p[y][i]){
      x = p[x][i];
      y = p[y][i];
    }
  }
  return p[x][0];
}

int main(){
  while(scanf("%d",&n), n){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < LOG; j++){
        p[i][j] = -1;
      }
    }
    for(int i = 1; i < n; i++){
      int j;
      ll c;
      scanf("%d %lld",&j,&c);
      g[i].push_back({j, c});
      g[j].push_back({i, c});
    }
    L[0] = 0;
    dfs(0, -1, 0L);
    int q;
    scanf("%d",&q);
    vector<ll> ans;
    for(int i = 0; i < q; i++){
      if(i) printf(" ");
      int a,b;
      scanf("%d %d",&a,&b);
      int LCA = lca(a, b);
      printf("%lld", cost[a] + cost[b] - cost[LCA] - cost[LCA]);
    }
    puts("");
    for(int i = 0; i < n; i++){
      g[i].clear();
    }
  }
  
  return 0;
}
