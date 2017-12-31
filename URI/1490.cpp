#include <bits/stdc++.h>

using namespace std;
int n;

const int N = 150;
char g[N][N];
vector<vector<int> > G;
int line[N][N];
vector<int> vis;
vector<int> match;

int dfs(int x){
  if(vis[x]) return 0;
  vis[x] = 1;
  
  for(int i = 0; i < G[x].size(); i++){
    int y = G[x][i];
    
    if(match[y] == -1 || dfs(match[y])){
      match[y] = x;
      return 1;
    }
  }
  return 0;
}


int main()
{ 
  
  while(scanf("%d", &n) != EOF){  
    G.clear();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        scanf(" %c", &g[i][j]);
        line[i][j] = -1;
      }
    }
    int idx = 0;
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(g[i][j] == 'X') {
          idx++;
        }
        else {
          line[i][j] = idx;
        }
      }
      idx++;
    }
    int limit = idx;
    G.resize(idx);
    for(int j = 0; j < n; j++){
      for(int i = 0; i < n; i++){
        if(g[i][j] == 'X'){
          idx++;
        }
        else{
          if(line[i][j] != -1){
            G[line[i][j]].push_back(idx);
          }
        }
      }
      idx++;
    }
    
    int maxMatching = 0;
    match.assign(idx, -1);
    for(int i = 0; i < limit; i++){
      vis.assign(idx, 0);
      maxMatching += dfs(i);
    }
    printf("%d\n", maxMatching);
  }
  
  return 0;
}
