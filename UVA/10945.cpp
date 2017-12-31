#include <bits/stdc++.h>

using namespace std;

int main(){
  string x;
  while(getline(cin, x) , x != "DONE"){
    bool ok = true;
    string s;
    for(int i = 0; i < x.size(); i++){
      if(!isalpha(x[i])) continue;
      s.push_back(tolower(x[i]));
    }
    for(int i = 0, j = s.size() - 1; i < j; i++, j--){
      s[i] = tolower(s[i]);
      s[j] = tolower(s[j]);
      if(s[i] != s[j]) ok = false;
    }
    if(ok) cout << "You won't be eaten!" << endl;
    else cout << "Uh oh.." << endl;
  }
  
  return 0;
}
