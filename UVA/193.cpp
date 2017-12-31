#include <bits/stdc++.h>

using namespace std;
const int N = 2e2+10;
vector<int> g[N];
int color[N];

void bfs(int x){
  queue<int> q;
  
  q.push(x);
  color[x] = 0;
  
  while(!q.empty()){
    int y = q.front();
    q.pop();
    for(auto u: g[y]){
      if(color[u] == -1){
        color[u] = (color[y] ^ 1);
        q.push(u);
      } else if(color[u] == color[y]){
        color[u] = 1;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  
  
  while(t--){
    int n,m;
    memset(color,-1,sizeof color);
    cin >> n >> m;
    while(m--){
      int a,b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    bfs(0);
    vector<int> ans;
    for(int i = 0; i < n; i++){
      if(color[i] == 0){
        ans.push_back(i + 1);
      }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
    for(int i = 0; i < n; i++){
      g[i].clear();
    }
  }
  
  return 0;
}
