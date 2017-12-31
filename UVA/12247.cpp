#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int a[3];
  int b[2];
  while(cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1]){
    set<int> v;
    
    for(int i = 0; i < 3; i++) v.insert(a[i]);
    for(int i = 0; i < 2; i++) v.insert(b[i]);
    if(v.size() == 1) break;
    sort(a, a + 3);
    sort(b, b + 2);
    for(int i = 0; i < 3; i++){
      if(b[1] < a[i]){
        b[1] = -1;
        a[i] = -1;
        break;
      }
    }
    int ans = -1;
    for(int i = 0; i < 3; i++){
      if(a[i] != -1 && b[0] < a[i]){
        b[0] = -1;
        a[i] = -1;
        break;
      }
    }
    if(b[0] != -1 || b[1] != -1){
      int x;
      if(b[0] != -1 && b[1] != -1){
        for(int i = 1; i <= 52; i++){
          if(v.find(i) == v.end()){
            ans = i;
            break;
          }
        }
      } else {
        for(int i = 2; i >= 0; i--){
          if(a[i] != -1) {
            x = i;
            break;
          }
        }
        for(int i = a[x] + 1; i <= 52; i++){
          if(v.find(i) == v.end()){
            ans = i;
            break;
          }
        }
      }
    }

    cout << ans << endl;
  }
}
