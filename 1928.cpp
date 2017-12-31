#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 5e4 + 10;
int L[N];
const int LOG = 16;
int cards[N];
map<int,pair<int,int> > par;
int p[N][LOG];
int custo[N];
vector<int> g[N];
void dfs(int x, int dad, int cost){
  p[x][0] = dad;
  L[x] = L[dad] - 1;
  custo[x] = cost;
  for(int i = 1; i < LOG; i++){
    p[x][i] = p[p[x][i - 1]][i - 1];
  }
  for(auto u: g[x]){
    if(u == dad) continue;
    dfs(u, x, cost + 1);
  }
}

int lca(int x, int y){
  if(L[x] > L[y]){
    swap(x, y);
  }
  for(int i = LOG - 1; i >= 0; i--){
    if(L[x] + (1 << i) <= L[y]){
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
  
  
  scanf("%d",&n);
  
  for(int i = 0; i < n; i++){
    scanf("%d",&cards[i]);
    if(!par.count(cards[i])){
      par[cards[i]].first = i;
    } else {
      par[cards[i]].second = i; 
    }
  }
  
  for(int i = 0; i < n - 1; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  L[0] = 0;
  dfs(0,0,0);
  map<int,pair<int,int> > :: iterator it;
  int ans = 0;
  for(it = par.begin(); it != par.end(); ++it){
    int u = it->second.first;
    int v = it->second.second;
    int LCA = lca(u, v);
    ans += (custo[u] + custo[v] - custo[LCA] - custo[LCA]);
  }
  printf("%d\n", ans);
  return 0;
}
