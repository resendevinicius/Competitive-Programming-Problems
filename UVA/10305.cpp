#include <bits/stdc++.h>
using namespace std;
int inc[111];
int n, m;
vector<int> g[111];
int main(){
  
  while(scanf("%d %d",&n,&m), n|m){
    queue<int> q;
    for(int i = 0; i < m; i++){
      int a,b;
      scanf("%d %d",&a,&b);
      a--; b--;
      g[a].push_back(b);
      inc[b]++;
    }
    for(int i = 0; i < n; i++){
      if(!inc[i]) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      for(auto u: g[x]){
        inc[u]--;
        if(!inc[u]) q.push(u);
      }
      ans.push_back(x);
    }
    for(int i = 0; i < n; i++) g[i].clear();
    for(int i = 0; i < ans.size(); i++){
      if(i) printf(" ");
      printf("%d", ans[i] + 1);
    }
    puts("");
  }
  return 0;
}
