#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cout << fixed << setprecision(0);
  cin >> t;
  
  while(t--){
    int n;
    cin >> n;
    double res = 0;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        res += (((double) a / b) * c * b);
    }
    cout << res << endl;
  }
  
  return 0;
}
