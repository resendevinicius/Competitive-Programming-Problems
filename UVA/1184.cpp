#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int vis[N], match[N];

vector<int> g[N];
bool dfs(int u){
  if(vis[u]) return 0;
  vis[u] = 1;
  for(int v: g[u]){
    if(match[v] == -1 || dfs(match[v])){
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

int main(){
  int t;
  
  scanf("%d",&t);
  memset(match,-1,sizeof match);
  while(t--){
    int n, m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++){
      int a,b;
      scanf("%d %d",&a,&b);
      a--; b--;
      g[b].push_back(a);
    }
    
    int ans = n;
    for(int i = 0; i < n; i++){
      memset(vis,0,sizeof vis);
      ans -= dfs(i);
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++){
      g[i].clear();
      match[i] = -1;
    }
  }
  
  return 0;
}
