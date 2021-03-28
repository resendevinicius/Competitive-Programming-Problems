#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
int n;
int caso;
const int N = 12;
char g[N][N];

struct node{
  pair<int,int> a,b,c;
  node(const pair<int,int> &a, const pair<int,int> &b, const pair<int,int> &c) : a(a), b(b), c(c){}
  bool operator < (const node &other) const {
    if(a != other.a) return a < other.a;
    if(b != other.b) return b < other.b;
    if(c != other.b) return c < other.c;
    return false;
  }
};
map<node,int> memo;
map<node,int> dist;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
pair<int,pair<int,int> > check(const pair<int,int> &aa, const pair<int,int> &bb, const pair<int,int> &cc){
  int a,b,c;
  a = b = c = 0;
  int x = aa.first;
  int y = aa.second;
  int xx = bb.first;
  int yy = bb.second;
  int xxx = cc.first;
  int yyy = cc.second;
  if((x >= 0 && y >= 0 && x < n && y < n)){
    if(g[x][y] == '.' || g[x][y] == 'X') a = 1;
  }
  if((xx >= 0 && yy >= 0 && xx < n && yy < n)){
    if(g[xx][yy] == '.' || g[xx][yy] == 'X') b = 1;
  }
  if((xxx >= 0 && yyy >= 0 && xxx < n && yyy < n)){
    if(g[xxx][yyy] == '.' || g[xxx][yyy] == 'X') c = 1;
  }
  return make_pair(a,make_pair(b,c));
}
int bfs(pair<int,int> &a, pair<int,int> &b, pair<int,int> &c){
  memo.clear();
  dist.clear();
  queue<node> q;
  q.push(node(a,b,c));
  memo[node(a,b,c)] = 1;
  dist[node(a,b,c)] = 0;
  while(!q.empty()){
    pair<int,int> r1 = q.front().a;
    pair<int,int> r2 = q.front().b;
    pair<int,int> r3 = q.front().c;
    q.pop();
    vector<pair<int,int>> caras;
    caras.push_back(r1);
    caras.push_back(r2);
    caras.push_back(r3);
    int distancia = dist[node(r1,r2,r3)];
    r1 = caras[0];
    r2 = caras[1];
    r3 = caras[2];
    
    if(g[r1.ff][r1.ss] == 'X' && g[r2.ff][r2.ss] == 'X' && g[r3.ff][r3.ss] == 'X') return distancia;
    
    for(int k = 0; k < 4; k++) {
      caras.clear();
      int i = r1.ff + dx[k];
      int j = r1.ss + dy[k];
      caras.push_back(make_pair(i,j));
      int ii = r2.ff + dx[k];
      int jj = r2.ss + dy[k];
      caras.push_back(make_pair(ii,jj));
      int iii = r3.ff + dx[k];
      int jjj = r3.ss + dy[k];
      caras.push_back(make_pair(iii,jjj));
      pair<int,int> nR1 = caras[0];
      pair<int,int> nR2 = caras[1];
      pair<int,int> nR3 = caras[2];
      
      pair<int,pair<int,int> > move = check(nR1, nR2, nR3);
      if(move.ff == 0 && move.ss.ff == 0 && move.ss.ss == 0) {
        continue;
      }
      
      if(move.ff && move.ss.ff && move.ss.ss && nR1 != nR2 && nR1 != nR3 && nR2 != nR3){
        node X = node(nR1,nR2,nR3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
      } else if(move.ff && move.ss.ff && nR1 != nR2 && nR1 != r3 && nR2 != r3){
        node X = node(nR1, nR2, r3);
        if(memo.count(X) == 0){
          memo[X] = 1;
          dist[X] = distancia + 1;
          q.push(X);
        }
        
      } else if(move.ff && move.ss.ss && nR1 != r2 && nR1 != nR3 && r2 != nR3){
        node X = node(nR1, r2, nR3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
      } else if(move.ss.ff && move.ss.ss && r1 != nR2 && r1 != nR3 && nR2 != nR3){
        node X = node(r1, nR2, nR3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
        
      } else if(move.ff && nR1 != r2 && nR1 != r3){
        node X = node(nR1, r2, r3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
      } else if(move.ss.ff &&  r1 != nR2 && nR2 != r3){
        node X = node(r1, nR2, r3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
        
      } else if(move.ss.ss && r1 != nR3 && r2 != nR3){
        node X = node(r1,r2, nR3);
        if(memo.count(X) == 0){
          dist[X] = distancia + 1;
          memo[X] = 1;
          q.push(X);
        }
      }
    }
  }
  return -1;
}

int main(){
  int t;
  scanf("%d",&t);
  
  while(t--){
    scanf(" %d",&n);
    vector<pair<int,int> > robos(3);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        scanf(" %c",&g[i][j]);
        if(g[i][j] == 'A'){
          robos[0] = make_pair(i, j);
          g[i][j] = '.';
        } else if(g[i][j] == 'B'){
          robos[1] = make_pair(i, j);
          g[i][j] = '.';
        } else if(g[i][j] == 'C'){
          robos[2] = make_pair(i, j);
          g[i][j] = '.';
        } 
      }
    }
    sort(robos.begin(), robos.end());
    int ans = bfs(robos[0],robos[1],robos[2]);
    
    
    printf("Case %d: ", ++caso);
    ans == -1 ? puts("trapped") : printf("%d\n", ans);
  }
  
  return 0;
}

