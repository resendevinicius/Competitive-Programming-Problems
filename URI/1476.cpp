#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 10;
const int LOG = 14;
vector<pair<int,int> > g[N];
vector<pair<int,pair<int,int> > > v;
#define INF 0X3F3F3F3F
int p[N][LOG];
int edge[N][LOG];
int L[N];
int pai[N];
int find(int n){
  return pai[n] = pai[n] == n ? n : find(pai[n]);
}
void merge(int a, int b){
  pai[find(a)] = find(b);
}
void dfs(int x, int dad){
  L[x] = L[dad] - 1;
  p[x][0] = dad;
  
  for(int i = 1; i < LOG; i++){
    p[x][i] = p[p[x][i - 1]][i - 1];
    edge[x][i] = min(edge[p[x][i - 1]][i - 1], edge[x][i - 1]);
  }
  for(auto u: g[x]){
    if(u.first == dad) continue;
    edge[u.first][0] = u.second;
    dfs(u.first, x);
  }
}

int lca(int x, int y){
  if(L[x] > L[y]){
    swap(x, y);
  }
  int ans = INT_MAX;
  for(int i = LOG - 1; i >= 0; i--){
    if(L[x] + (1 << i) <= L[y]){
      ans = min(ans, edge[x][i]);
      x = p[x][i];
    }
  }
  if(x == y) return ans;
  for(int i = LOG -1; i >= 0; i--){
    if(p[x][i] != p[y][i]){
      ans = min(ans, edge[x][i]);
      ans = min(ans, edge[y][i]);
      x = p[x][i];
      y = p[y][i];
    }
  }
  return min(ans, min(edge[x][0], edge[y][0]));
}

int main(){
  
  int n,m,s;
  while(scanf("%d %d %d",&n,&m,&s) != EOF){
    int a,b,c;
    for(int i = 0; i < m; i++){
      scanf("%d %d %d",&a,&b,&c);
      a--; b--;
      v.push_back(make_pair(c, make_pair(a,b)));
    }
    for(int i = 0; i < n; i++) pai[i] = i, edge[i][0] = INF;
    sort(v.rbegin(), v.rend());
    
    for(auto u: v){
      a = u.second.first;
      b = u.second.second;
      c = u.first;
      if(find(a) != find(b)){
        merge(a, b);
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
      }
    }
    L[0] = 0;
    dfs(0,0);
    while(s--){
      scanf("%d %d",&a,&b);
      a--; b--;
      printf("%d\n", lca(a,b));
    }
    for(int i = 0; i < n; i++){
      g[i].clear();
    }
    v.clear();
  }
  return 0;
}
