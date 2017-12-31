//@Author: Vinícius Resende. 09/12/2017 - 13:27:07
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int v[N];
int main(){
  int n;
  
  while(scanf("%d",&n), n){
    for(int i = 0; i < n; i++){
      scanf("%d",&v[i]);
    }
    stack<int> s;
    long long int ans = 0;
    int top = 0;
    for(int i = 0; i <= n; i++){
      int a = i == n ? 0 : v[i];      
      while(!s.empty() && a <= v[s.top()]){
        int top = s.top();
        s.pop();
        if(s.empty()){
          ans = max(ans, (long long) v[top] * i);
        } else {
          ans = max(ans, (long long) v[top] * (i - s.top() - 1));
        }
      }
      s.push(i);
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
