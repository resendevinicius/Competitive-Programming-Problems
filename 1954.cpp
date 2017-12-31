#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int vis[N];
vector<int> g[N], g2[N];
set<int> grafo[N];
int n,m,s,t;
vector<int> order;
int SCC[N];
int nScc;
int pd[N];
int memo[N];
const int mod = 1e9 + 7;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void add(int &a, int b){
  a += b;
  if(a >= mod) a -= mod;
}
int f(const int u){
  if(u == t) return 1;  
  if(memo[u]) return pd[u];
  int ans = 0;
  for(int v: grafo[u]){
    add(ans, f(v));
  }
  memo[u] = 1;
  return pd[u] = ans;
}
void dfs(int x){
  vis[x] = 1;
  for(int u: g[x]) if(!vis[u]) dfs(u);
  order.push_back(x);
  vis[x] = 2;
}
void dfst(int x){
  vis[x] = 1;
  SCC[x] = nScc;
  for(int u: g2[x]) if(!vis[u] || vis[u] == 2) dfst(u);
}

int main(){
  scanint(n);
  scanint(m);
  scanint(s);
  scanint(t);
  int a,b;
  while(m--) {
    scanint(a);
    scanint(b);
    a--; b--;
    g[a].push_back(b);
    g2[b].push_back(a);
  }
  for(int i = 0; i < n; i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  for(int i = (int) order.size() - 1; i >= 0; i--){
    if(!vis[order[i]] || vis[order[i]] == 2){
      dfst(order[i]);
      nScc++;
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int u: g[i]){
      if(SCC[i] != SCC[u]){
        grafo[SCC[i]].insert(SCC[u]);
      }
    }
  }
  s--; t--;
  s = SCC[s];
  t = SCC[t];
  printf("%d\n", f(s));
  return 0;
}
