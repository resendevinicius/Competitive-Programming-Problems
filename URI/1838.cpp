#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
struct interval{
  int s, f, w;

  bool operator < (const struct interval &other) const {
    return f < other.f;
  }
};
typedef struct interval Interval;

bool compare(Interval &a, int x){
  return a.f <= x;
}

int dp[N];
int n;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  Interval v[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> v[i].s >> v[i].f;
    v[i].w = v[i].f - v[i].s;
  }
  sort(v + 1, v + n + 1);
  dp[0] = 0;
  vector<Interval> V (v, v + n + 1);
  for(int i = 1; i <= n; i++){
    int t = lower_bound(V.begin() + 1, V.begin() + 1 + i, V[i].s, compare) - V.begin() - 1;
    dp[i] = max(dp[i - 1], dp[t] + v[i].w);
  }
  cout << dp[n] << endl;
  
  return 0;
}
