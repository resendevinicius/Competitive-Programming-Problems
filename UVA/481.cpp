#include <bits/stdc++.h>

using namespace std;

vector<int> v, v2;
const int N = 1e6 + 10;
map<int,int> idx;
int dp[N];
int st[N << 2];
#define INF 0x3f3f3f3f
int query(int id, int l, int r, int i, int j){
  if(l > j || r < i) return -INF;
  if(l >= i && r <= j) return st[id];
  int mid = (l + r) >> 1;
  int a = query(id * 2, l, mid, i, j);
  int b = query(id * 2 + 1, mid + 1, r, i, j);
  return max(a,b);
}
void update(int id, int l, int r, int i, int j, int x){
  if(l > j || r < i) return;
  if(l >= i && r <= j) {
    st[id] = x;
    return;
  }
  int mid = (l + r) >> 1;
  update(id * 2, l, mid, i, j, x);
  update(id * 2 + 1, mid + 1, r, i, j, x);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n){
    v.push_back(n);
    v2.push_back(n);
  }  
  sort(v2.begin(), v2.end());
  int k = 1;
  for(int i = 0; i < v2.size(); i++){
    if(!idx.count(v2[i])){
      idx[v2[i]] = k++;
    }
  }
  
  for(int i = 0; i < v.size(); i++){
    dp[i] = query(1,0,k-1,0,idx[v[i]] - 1) + 1;
    update(1,0,k - 1,idx[v[i]],idx[v[i]], dp[i]);
  }
  int maximum = query(1,0,k-1,0,k-1);
  vector<int> ans;
  cout << maximum << endl;
  cout << "-" << endl;
  for(int i = v.size() - 1; i >= 0; i--){
    if(dp[i] == maximum) {
      ans.push_back(v[i]);
      maximum--;
    }
  }
  for(int i = ans.size() - 1; i >= 0; i--){
    cout << ans[i] << endl;
  }
  return 0;
}
