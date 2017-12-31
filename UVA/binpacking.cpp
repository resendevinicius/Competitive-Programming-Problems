#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int v[N];
int n,m;

int main(){
  
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  if(m == 1){
    cout << *min_element(v, v + n) << endl;
  } else if(m >= 3){
    cout << *max_element(v, v + n) << endl;
  } else {
    cout << max(v[0], v[n - 1]) << endl;
  }
  return 0;
}
