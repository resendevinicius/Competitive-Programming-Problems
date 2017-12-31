#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e3 + 10;
char g[N][N];
int dis[N][N];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<int,int> > q;
int bfs(){
  int ans = 0;
  while(!q.empty()){
    int x = q.front().first, y = q.front().second;
    q.pop();
    if(g[x][y] == '3') {
      return dis[x][y];

    }
    for(int i = 0; i < 4; i++){
      int ii = dx[i] + x;
      int jj = dy[i] + y;
      if(ii < 0 || ii >= n || jj < 0 || jj >= n || dis[ii][jj] != -1 || g[ii][jj] == '1'){
        continue;
      }
      dis[ii][jj] = dis[x][y] + 1;
      q.push(make_pair(ii,jj));
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  while(cin >> n){
    queue<pair<int,int> > aux;
    q = aux;
    memset(dis,-1,sizeof dis);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> g[i][j];
        if(g[i][j] == '1'){
          dis[i][j] = 0;
          q.push(make_pair(i,j));
        }
      }
    }
    cout << bfs() << endl;
  }
  return 0;
}
