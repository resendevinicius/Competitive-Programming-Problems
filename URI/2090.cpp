#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  while(scanf("%d %d",&n,&k), n | k){
    string s[n];
    char str[22];
    k--;
    for(int i = 0; i < n; i++){
      scanf(" %s", str);
      s[i] = (string) str;
    }
    for(int i = 0; i < n; i++){
      if(k < i){
        printf("%s\n", s[k].c_str());
        break;
      }
      k -= i + 1;
    }
    
  }
  return 0;
}
