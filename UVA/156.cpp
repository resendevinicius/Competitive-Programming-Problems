#include <bits/stdc++.h>


using namespace std;
struct anagram {
  int alp[26];
  string s;
  anagram(){
    memset(alp,0,sizeof alp);
  }
  void start(){
    for(int i = 0; i < this->s.size(); i++){
      this->alp[tolower(s[i]) - 'a']++;
    }
  }
  bool operator==(const anagram other) const{
    for(int i = 0; i < 26; i++) if(this->alp[i] != other.alp[i]) return false;
    return true;
  }
};
vector<anagram> v;
const int N = 1e5 + 10;
bool done[N];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  set<string> V;
  string s;
  while(cin >> s, s != "#"){
    V.insert(s);
  }
  for(string y: V){
    anagram x;
    x.s = y;
    x.start();
    v.push_back(x);
  }
  for(int i = 0; i < V.size(); i++){
    bool ok = true;
    if(done[i]) continue;
    for(int j = i + 1; j < V.size(); j++){
      if(v[i] == v[j]) {
        ok = false;
        done[j] = true;
      }
    }
    if(ok) cout << v[i].s << endl;
  }
  return 0;
}
