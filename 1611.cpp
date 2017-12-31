#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int t;
  scanf("%d",&t);
  
  while(t--){
    int n,c,m;
    
    scanf("%d %d %d",&n,&c,&m);
    vector<int> v;
    for(int i = 0; i < m; i++){
      int x; 
      scanf("%d",&x);
      v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    int range = 0;
    for(int i = 0; i < m; i++){
      range = max(range, v[i]);
      if((i + 1) % c == 0){
        res += range;
        range = 0;
      }
    }
    if(range != 0){
      res += range;
    }
    printf("%d\n", res * 2);
  }
  
  return 0;
}
