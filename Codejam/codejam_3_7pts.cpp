#include <bits/stdc++.h>

using namespace std; int f(vector<int> v){
  int ans = 0;
  for (int i = 0; i < (int) v.size() - 1; ++i) {
    int j = min_element(v.begin() + i, v.end()) - v.begin();
    reverse(v.begin() + i, v.begin() + j + 1);
    ans += (j - i + 1);
  }
  return ans;
}
int main() {
  map<pair<int,int>, vector<int> > v;
  for (int i = 1; i <= 7; ++i) {
    vector<int> s(i);
    for(int j = 1; j <= i; ++j) {
      s[j - 1] = j;
    }
    do {
      v[{i, f(s)}] = s;
    } while (next_permutation(s.begin(), s.end()));
  }
  int t;
  cin >> t;
  int caso = 0;
  while (t--) {
    int n, c; cin >> n >> c;
    cout << "Case #" << ++caso << ": ";
    if (v.count({n, c})) {
      vector<int> ans = v[{n, c}];
      for (int i = 0; i < (int) ans.size(); ++i) {
        if(i) cout << ' ';
        cout << ans[i];
      }
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << '\n';
  }
  

  return 0;
}
