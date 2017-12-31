#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  int caso = 0;
  while(cin >> n){
    map<string, int> mapa;
    string s[n];
    for(int i = 0; i < n; i++){
      cin >> s[i];
      mapa[s[i]] = i;
    }
    vector<int> g[n];
    int inc[n];
    memset(inc,0,sizeof inc);
    cin >> m;
    int idx = 0;
    for(int i = 0; i < m; i++){
      string a, b;
      cin >> a >> b;
      g[mapa[a]].push_back(mapa[b]);
      inc[mapa[b]]++;
    }
    vector<string> ans;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < n; i++){
      if(!inc[i]){
        q.push(i);
      }
    }
    while(!q.empty()){
      int x = q.top();
      q.pop();
      for(auto u: g[x]){
        inc[u]--;
        if(!inc[u]) q.push(u);
      }
      ans.push_back(s[x]);
    }
    cout <<"Case #"<< ++caso << ": Dilbert should drink beverages in this order: ";
    for(int i = 0; i < ans.size(); i++){
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << "."<< endl << endl;
  }
  
  return 0;
}
