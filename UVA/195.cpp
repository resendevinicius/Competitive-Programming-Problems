#include <bits/stdc++.h>

using namespace std;
bool cmp(const string &a, const string &b){
  for(int i = 0; i < a.size(); i++){
    if(a[i] != b[i]){
      if(isupper(a[i]) && isupper(b[i])) return a[i] < b[i];
      if(tolower(a[i]) == tolower(b[i])){
        return isupper(a[i]);
      }
      return tolower(a[i]) < tolower(b[i]);
    }
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  string s;
  while(t--){
    cin >> s;
    sort(s.begin(), s.end());
    set<string> v;
    do {
      if(v.find(s) == v.end()){
        v.insert(s);
      }
    } while(next_permutation(s.begin(), s.end()));
    vector<string> ans;
    for(string a : v){
      ans.push_back(a);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++)
      cout << ans[i] << endl;
  }
  
  return 0;
}
