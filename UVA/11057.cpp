#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int cas = 0;
  while(cin >> n){
    int v[n];
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    int x;
    cin >> x;
    sort(v, v + n);
    int dif = INT_MAX;
    int a, b;
    for(int i = 0; i < n; i++){
      int c = x - v[i];
      if(binary_search(v, v + n, c) && abs(c - v[i]) < dif){
        a = v[i];
        b = c;
        dif = abs(a - b);
      }
    }
    string s;
    getline(cin, s);
    cout << "Peter should buy books whose prices are " << min(a, b) << " and " << max(a, b) << "." << endl << endl;
  }
  
  return 0;
}
