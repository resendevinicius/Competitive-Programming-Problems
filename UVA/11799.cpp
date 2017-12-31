#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  int caso = 0;
  while(t--){
    int n;
    cin >> n;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      ans = max(ans , x);
    }
    cout << "Case " << ++caso << ": ";
    cout << ans << endl;
  }
  
  return 0;
}
