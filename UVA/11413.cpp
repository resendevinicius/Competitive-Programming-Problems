#include <bits/stdc++.h>

using namespace std;
#define int double
int n, c;
const int N = 1e3 + 10;
int v[N];

bool check(int x){
  int sum = 0;
  int k = 0;
  for(int i = 0; i < n; i++){
    sum += v[i];
    if(sum > x){
      k++;
      sum = v[i];
    }
  }
  if(k >= c){
    return true;
  } else {
    return false;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  while(cin >> n >> c){
    for(int i = 0; i < n; ++i){
      cin >> v[i];
    }
    
    int hi = 1e12;
    int lo = *max_element(v, v + n);
    int ans = 0;
    for(int i = 0; i < 100; i++){
      int mid = lo + (hi - lo) / 2;
      if(check(mid)){
        lo = mid;
      } else {
        hi = mid; 
      }
    }
    cout << hi << endl;
  }
  
  return 0;
}
