#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  int n;
  while(cin >> n){
    v.push_back(n);
    
    sort(v.begin(), v.end());
    if(v.size() % 2 == 0){
      cout << (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2 << endl;
    } else {
      cout << v[v.size() / 2] << endl;
    }

  }
  
  
  return 0;
}
