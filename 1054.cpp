#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int caso = 0;
  while(t--){
    int n, d;
    
    cin >> n >> d;
    char a,b;
    int c;
    int ans = 0;
    vector<pair<char, int> > v, v2;
    bool ok = false;
    for(int i = 0; i < n; i++){
      cin >> a >> b >> c;
      if(a == 'B'){
        v.push_back(make_pair(a,c));
        v2.push_back(make_pair(a,c));
      } else {
        if(!ok){
          v.push_back(make_pair(a,c));
          ok = true;
        } else {
          v2.push_back(make_pair(a,c));
          ok = false;
        }
      }
    }
    int last = 0;
    for(int i = 0; i < v.size(); i++){
      ans = max(ans, v[i].second - last);
      last = v[i].second;
    }
    ans = max(d - last, ans);
    last = d;
    for(int i = (int) v2.size() - 1; i >= 0; i--){
      ans = max(ans, last - v2[i].second);
      last = v2[i].second;
    }
    ans = max(ans, last);
    cout << "Case " << ++caso << ": " << ans << endl;
  }
  return 0;
}
