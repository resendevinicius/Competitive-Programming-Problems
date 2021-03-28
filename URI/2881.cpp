#include <bits/stdc++.h>

using namespace std;
#define pb emplace_back
#define debug(x) cerr << #x << " = " << x << endl
int n;
const int N = 1001;
int dp[N][(1 << 10)];
bool memo[N][(1 << 10)];

#define INF 0x3f3f3f3f
vector<tuple<int,int,int,int> > v;

int f(int at, int mask){
  if(at == v.size()) {
    if((1 << n) - 1 == mask) return 0;
    else return -INF; 
  } 
  if(memo[at][mask]) return dp[at][mask];
  int findNext = lower_bound(v.begin() + at, v.end(), make_tuple(get<1> (v[at]), -1, -1, -1)) - v.begin();
  int palco = get<3> (v[at]);
  dp[at][mask] = max(f(findNext, (1 << palco) | mask) + get<2> (v[at]), f(at + 1, mask));
  memo[at][mask] = 1;
  return dp[at][mask];
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;

  for(int i = 0; i < n; i++){
    int m;
    cin >> m;
    for(int j = 0; j < m; j++){
      int x, y, z;
      cin >> x >> y >> z;
      v.pb(x, y, z, i);
    }
  }
  
  sort(v.begin(), v.end());
  memset(memo, 0, sizeof memo);
  
  int ans = f(0, 0);
  if(ans > 0) cout << ans << '\n';
  else cout << -1 << '\n';

  return 0;
}
