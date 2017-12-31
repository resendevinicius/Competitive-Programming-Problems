#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int v[N];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  int caso = 0;
  while(cin >> n, n){
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> v[i];
      sum += v[i];
    }
    sum /= n;
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(v[i] < sum){
        ans += (sum - v[i]);
      }
    }
    cout << "Set #" << ++caso << endl; 
    cout << "The minimum number of moves is " << ans << "." << endl << endl;
  }
  
  
  return 0;
}
