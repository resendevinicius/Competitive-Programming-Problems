#include <bits/stdc++.h>

using namespace std;

int n, m;
const int N = 1e3 + 10;
vector<int> vis;
vector<int> match;
vector<int> g[N];
int dfs(int x){
  if(vis[x]) return 0;
  cout << x + 1 << endl;
  vis[x] = 1;
  for(auto u: g[x]){
    if(match[u] == -1 || dfs(match[u])){
      match[u] = x;
      return 1;
    }
  }
  return 0;
}

int main(){
  
  while(scanf("%d %d",&n,&m) != EOF){
    
    for(int i = 0; i < m; i++){
      int a,b;
      scanf("%d %d",&a,&b);
      a--; b--;
      g[b].push_back(a);
      cout << b + 1<< " " << a+ 1 << endl;
    }
    
    match.assign(n, -1);
    int ans = n;
    for(int i = 0; i < n; i++){
      vis.assign(n, 0);
      ans -= dfs(i);
    }
    for(int i = 0; i < n; i++){
      if(match[i] != -1){
        cout << i + 1 << " " << match[i] + 1 << endl;
      }
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++){
      g[i].clear();
    }
  }
  
  return 0;
}
