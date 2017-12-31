#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int t;
  scanf("%d ",&t);
  
  while(t--){
    vector<int> v;
    int n;
    scanf("%d",&n);
    for(int i = 0; i <= n; i++){
      int x;
      scanf("%d",&x);
      v.push_back(x);
    }
    int d, k;
    scanf(" %d %d",&d,&k);
    int aux = d;
    vector<int> ans;
    for(int i = 0; i < v.size(); i++){
      ans.push_back(v[i] * d);
      d += aux;
      cout << ans.back() << endl;
    }
    int x = 0;
    for(int i = 1; i <= k; i += aux){
      x++;
    }
    x--;
    cout << ans[x] << endl;
    getchar();  
  }
  
  return 0;
}
