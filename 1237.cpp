#include <bits/stdc++.h>
using namespace std;

char a[55], b[55];
int n,m;
int main(){
  
  
  while(scanf(" %[^\n]s", a) != EOF){
    scanf(" %[^\n]s", b);
    int res = 0;
    n = strlen(a);
    m = strlen(b);
    int ans = 0;
    
      for(int i = 0; i < n; i++){
        int cnt = 0;
        int aux = i;
        for(int j = 0; j < m; j++){
          if(a[i] == b[j]){
            cnt++;
            i++;
          } else {
            ans = max(ans, cnt);
            i -= cnt;
            cnt = 0;
          }
        }
        i = aux;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
