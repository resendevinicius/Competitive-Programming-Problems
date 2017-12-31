#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(3);
  
  int t;
  cin >> t;
  
  while(t--){
    int n;
    cin >> n;
    int v[n];
    double sum = 0;
    for(int i = 0; i < n; i++){
      cin >> v[i];
      sum += v[i];
    }
    sum /= n;
    int c = 0;
    for(int i = 0; i < n; i++){
      if((double) v[i] > sum){
        c++;
      }
    }
    cout << c / (double) n  * 100. << "%" <<  endl;
  }
  return 0;
}
