#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  int caso = 0;
  while(t--){
    vector<string> v;
    string s;
    for (int i = 0; i < 52; i++){
      cin >> s;
      v.push_back(s);      
    }
    int y = 0;
    for(int i = 0; i < 3; i++){
       vector<string> hand;  
       hand.insert(hand.begin(),v.begin() + (int) v.size() - 25, v.end());
       v.erase(v.begin() + (int) v.size() - 25, v.end());
       int x = isdigit(v.back()[0]) ? v.back()[0] - '0' : 10;
       y += x;
       v.pop_back();
       for(int j = 0; j < 10 - x; j++) {
          v.pop_back();
       }
       v.insert(v.end(), hand.begin(), hand.end());
    }
    cout << "Case " << ++caso << ": ";
    cout << v[y - 1] << endl;
  }
  
  return 0;
}
