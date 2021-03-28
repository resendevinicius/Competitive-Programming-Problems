#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

int dp[N][2];
int v[N];
int x, y;
int n, m;
#define INF 0x3F3F3F3F
int st[4 * N][2];


void update(int vtx, int l, int r, int i, int val, int p){
  if(l == r){
    st[vtx][p] = val;
    return;
  }
  
  int mid = (l + r) / 2;
  if(i <= mid){
    update(vtx * 2, l, mid, i, val, p);
  } else {
    update(vtx * 2 + 1, mid + 1, r, i, val, p);
  }

  st[vtx][p] = min(st[vtx * 2][p], st[vtx * 2 + 1][p]);
}


int query(int vtx, int l, int r, int i, int j, int p){
  if(l > j || r < i){
    return INF;
  }
  if(l >= i && r <= j){
    return st[vtx][p];
  }
  int mid = (l + r) / 2;
  int a = query(vtx * 2, l, mid, i, j, p);
  int b = query(vtx * 2 + 1, mid + 1, r, i, j, p);
  return min(a, b);
}


int main(){

  scanf("%d %d", &n, &m);
  v[0] = 1;
  for(int i = 1; i <= n; i++){
    scanf("%d", &v[i]);
  }
  v[n + 1] = m;
  n += 2;
  scanf("%d %d", &x, &y);

  memset(st, INF, sizeof st);
  memset(dp, INF, sizeof dp);

  int xjump[n];
  int yjump[n];

  for(int i = 1; i < n; i++){
    xjump[i] = lower_bound(v, v + i + 1, v[i] - x) - v;
    yjump[i] = lower_bound(v, v + i + 1, v[i] - y) - v;
  }

  dp[0][1] = dp[0][0] = 0;
  update(1, 0, n - 1, 0, dp[0][1], 1);
  update(1, 0, n - 1, 0, dp[0][0], 0);

  for(int pos = 1; pos < n; pos++){
    dp[pos][1] = query(1, 0, n - 1, yjump[pos], pos - 1, 0) + 1; 
    dp[pos][0] = query(1, 0, n - 1, xjump[pos], pos - 1, 0) + 1; 
    dp[pos][1] = min(dp[pos][1], dp[pos][0]);
    dp[pos][0] = min(dp[pos][0], query(1, 0, n - 1, xjump[pos], pos - 1, 1) + 1);
    
    update(1, 0, n - 1, pos, dp[pos][1], 1);
    update(1, 0, n - 1, pos, dp[pos][0], 0);
  }
  int ans = min(dp[n - 1][0], dp[n - 1][1]);

  printf("%d\n", (ans == INF + 1 ? -1 : ans));
  
  return 0;
}   
