#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  int caso = 0;
  while(t--){
    int n;
    scanf("%d",&n);
    char v[n + 3];
    v[n] = v[n + 1] = v[n + 2] = '#';
    scanf(" %s",&v);
    int ans = 0;
    for(int i = 0; i < n; i++){
      if(v[i] == '.'){
        v[i] = v[i + 1] = v[i + 2] = '#';
        ans++;
      }
    }
    printf("Case %d: %d\n", ++caso,  ans);
  }
  
  return 0;
}
