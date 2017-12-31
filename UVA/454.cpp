#include <bits/stdc++.h>

using namespace std;

struct anagram {
  int alp[256];
  string s;
  anagram(){ 
    memset(alp,0,sizeof alp);
  }
  void start(){
    for(int i = 0; i < this->s.size(); i++){
      if(s[i] == ' ') continue;
      alp[s[i]]++;
    }
  }
  bool operator == (anagram &other)  {
    for(int i = 0; i < 256; i++){
      if(alp[i] != other.alp[i]) return false;
    }
    return true;
  }
  bool operator < (const anagram &other) const {
    return this->s < other.s;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int linha = 0;
  string s;
  cin.ignore();
  getline(cin, s);
  while(t--){    
    vector<anagram> v;
    if(linha++) {
      cout << endl;
    }
    while(getline(cin, s) && s != ""){
      anagram x;
      x.s = s;
      x.start();
      v.push_back(x);
    }
    set<int> used;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
      if(used.find(i) != used.end()) continue;
      for(int j = i + 1; j < v.size(); j++){
        if(v[i] == v[j]){
          if(v[i].s > v[j].s) swap(v[i].s, v[j].s);
          cout << v[i].s << " = " << v[j].s << endl;
        }
      }
    }
    linha++;
  }
  return 0;
}
