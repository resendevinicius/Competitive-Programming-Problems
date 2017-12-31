#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > g;
vector<int> vis, match;
bool dfs(int x){
  if(vis[x]) return 0;
  vis[x] = 1;
  for(int u: g[x]){
    if(match[u] == -1 || dfs(match[u])){
      match[u] = x;
      return 1;
    }
  }
  return 0;
}

int T[555];
int walk[555];
int a[555];
int b[555];
int c[555];
int d[555];
int main(){
  
  int t;
  scanf("%d",&t);
  
  while(t--){
    int m;
    scanf("%d",&m);
    vector<int> v;
    for(int i = 0; i < m; i++) {
      int  h, mi;
      scanf("%d:%d %d %d %d %d",&h,&mi,&a[i],&b[i],&c[i],&d[i]);
      T[i] = 60 * h + mi;
      walk[i] = abs(a[i]-c[i]) + abs(b[i]-d[i]);
    }
    g.assign((m * 2) + 5, vector<int>());
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m; j++){
        int A = abs(a[j] - c[i]) + abs(b[j] - d[i]); 
        if(T[j] > T[i] + walk[i] + A){
          g[j].push_back(i + m);
        }
      }
    }
    int ans = 0;
    match.assign((m * 2) + 5, -1);
    for(int i = 0; i < m; i++){
      vis.assign(m + 5, 0);
      ans += dfs(i);
    }
    printf("%d\n", m -  ans);
  }
  return 0;
}
