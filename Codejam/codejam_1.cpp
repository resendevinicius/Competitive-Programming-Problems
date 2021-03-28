#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int caso = 0;
  while(t--){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
      int j = min_element(v.begin() + i, v.end()) - v.begin() + 1;
      reverse(v.begin() + i, v.begin() + j);
      ans += (j - i);
    }    
    cout << "Case #" << ++caso << ": " << ans << '\n';
  }
}
