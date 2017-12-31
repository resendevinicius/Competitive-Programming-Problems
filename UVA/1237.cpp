#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cout << 0b11111001 << endl;
  return 0;
  cin >> t;
  int caso = 0;
  while(t--){
    int n;
    cin >> n;
    if(caso++) cout << endl;
    vector<pair<string,pair<int,int> > > v;
    for(int i = 0; i < n; i++){
      string s;
      int a,b;
      cin >> s >> a >> b;
      v.push_back(make_pair(s,make_pair(a,b)));
    }
    int q;
    cin >> q;
    
    while(q--){
      int x;
      cin >> x;
      string ans;
      int c = 0;
      for(int i = 0; i < n; i++){
        if(x >= v[i].second.first && x <= v[i].second.second){
          ans = v[i].first;
          c++;
        }
      }
      if(c == 1){
        cout << ans << endl;
      } else {
        cout << "UNDETERMINED" << endl;
      }
    }
    
    
    
  }
  return 0;
}
