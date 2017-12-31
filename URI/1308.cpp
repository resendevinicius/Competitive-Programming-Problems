#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main(){
  
  int n;
  cin >> n;
  
  while(n--){
    int x;
    cin >> x;
    cout << (int)((-1 + sqrt(1 + x * 8.)) / 2.) << endl;
  }
  
  return 0;
}
