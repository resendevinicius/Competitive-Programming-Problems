#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 5;
int n;
int pd[N][N][2];
int v[N];

int f(int i, int last){
  if(i == n) return 0;
  
  if(pd[i][last] != -1) return pd[i][last];
  
  int ans = f(i + 1, last);
  
  if(last == i || v[i] > v[last]){
    ans = max(ans, f(i + 1, i) + 1);
  }
  return pd[i][last] = ans;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        pd[i][j] = -1;
      }
    }
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    cout << f(0,0) << endl;
  }
  
  
  return 0;
}
