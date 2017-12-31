#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  int ok = 0;
  while(cin >> n, n){
    int v[n];
    if(ok++) cout << endl;
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    sort(v, v + n);
    int jump = 1;
    int tmp = 1;
    for(int i = 1; i < n; i++){
      if(v[i] == v[i - 1]){
        tmp++;
      } else {
        jump = max(jump, tmp);
        tmp = 1;
      }
    }
    jump = max(jump, tmp);
    cout << jump << endl;
    for(int i = 0; i < jump; i++){
      cout << v[i];
      for(int j = i + jump; j < n; j += jump){
        cout << " " << v[j];
      }
      cout << endl;
    }
  }
  
  
  return 0;
}
