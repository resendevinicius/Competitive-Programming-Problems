#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  while(cin >> s, s != "#"){
    string x = s;
    sort(x.begin(), x.end());
    next_permutation(s.begin(), s.end());
    if(x == s) cout << "No Successor" << endl;
    else cout << s << endl;
  }
  
  
  return 0;
}
