#include <bits/stdc++.h>

using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int v[n + 5];
    for(int i = 1; i <= n; i++){
      cin >> v[i];
    }
    int sum = 0;
    for(int i = 2; i <= n; i ++){
      int c = 0;
      for(int j = 1; j < i; j++){
        if(v[j] <= v[i]){
          c++;
        }
      }
      sum += c;
    }
    cout << sum << endl;
  }
  
  return 0;
}
