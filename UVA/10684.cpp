#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n, n){
    int v[n];
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    int ans = INT_MIN;
    int at = 0;
    for(int i = 0; i < n; i++){
      at += v[i];
      ans = max(at, ans);
      if(at < 0) at = 0;
    }
    if(ans > 0){
      cout << "The maximum winning streak is " << ans <<".\n";
    } else {
      cout << "Losing streak." << endl;
    }
    
  }
  
  
  return 0;
}
