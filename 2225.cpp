#include <bits/stdc++.h>

using namespace std;
int n,m;
#define INF 0x3F3F3F3F

vector<pair<int,int> > g[16];

int dis[15][(1 << 15) + 5][6];
struct node{
  
  int adj, cost, k, mask;
  node(){
  }
  node(int adj, int cost, int k, int mask) : adj(adj), cost(cost), k(k), mask(mask) {}
  
  bool operator < (const node &other) const{
    return cost > other.cost;
  }
  
};
int dijkstra(int k){
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < (1 << n); j++)
      for(int l = 0; l <= k; l++)
        dis[i][j][l] = INF;
  
  priority_queue<node> q;
  q.push(node(0,0,k,1));  
  
  dis[0][1][k] = 0;
  
  
  while(!q.empty()){
    int x = q.top().adj, w = q.top().cost, p = q.top().k, mask = q.top().mask;
    q.pop();
    if((1 << n) - 1 == mask){
      return dis[x][mask][p];
    }
    
    if(dis[x][mask][p] < w){
      continue;
    }
  
    for(int i = 0; i < g[x].size(); i++){
      int y = g[x][i].first, c = g[x][i].second;
      int newMask = (1 << y) | mask;
      
      if(dis[y][newMask][p] > dis[x][mask][p] + c){
        dis[y][newMask][p] = dis[x][mask][p] + c;
        q.push(node(y,dis[y][newMask][p], p, newMask));
      }
    }
    if(p >= 1){
      for(int i = 0; i < n; i++){
        int newMask = (1 << i) | mask;
        if(dis[i][newMask][p - 1] > dis[x][mask][p]){
          dis[i][newMask][p - 1] = dis[x][mask][p];
          q.push(node(i,dis[i][newMask][p - 1], p - 1,newMask));
        }
      }
    }
  }
  return INF;
}

void init(){
  for(int i = 0; i < n; i++){
    g[i].clear();
  }
}

int main(){

  int k, t;
  
  scanf("%d",&t);
  
  while(t--){
    
    scanf("%d %d %d",&n,&m,&k);
    
    for(int i = 0; i < m; ++i){
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      a--; b--;
      g[a].push_back(make_pair(b,c));
      g[b].push_back(make_pair(a,c));
    }
    if(k >= n - 1){
      printf("0\n");
      init();
      continue;
    }
    int ans = dijkstra(k);
    init();
    printf("%d\n", ans == INF ? -1 : ans);
    
  }
  
  return 0;
}
