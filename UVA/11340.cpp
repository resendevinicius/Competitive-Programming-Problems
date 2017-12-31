#include <bits/stdc++.h>

using namespace std;
int main(){
  
  int t;
  
  scanf("%d",&t);
  while(t--){
    int k;
    scanf(" %d",&k);
    map<char,int> v;
    while(k--){
      char a;
      int b;
      scanf(" %c %d",&a,&b);
      v[a] = b;
    }
    int n;
    scanf("%d ",&n);
    double ans = 0.;
    char c;
    while(n--){      
      while(scanf("%c",&c) && c != '\n'){
        ans += (v.count(c) ? (v[c] / 100.) : 0);
      }
    }
    printf("%.2lf$\n", ans);
  }
  
  
  return 0;
}
