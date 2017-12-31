#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int n,m;
int pd[N];
const int mod = 1000000007;
char memo[N];
int v[N];
int f(int j){
  
  if(j >= n){    
    return 1;
  }
  if(memo[j] == '1'){
    return pd[j];
  }
  int ans = 0;
  
  for(int k = 0; k < m; k++){
    ans += (f(j + v[k]) % mod);  
    ans %= mod; 
  }
  memo[j] = '1';
  return pd[j] = ans;
}

int main(){
  
  int t;
  
  scanf("%d",&t);
  
  while(t--){
    scanf("%d %d",&n,&m);
    memset(memo,'0',sizeof memo);
    for(int i = 0; i < m; i++){
      scanf("%d",&v[i]);
    }
    printf("%d\n", f(0) % mod);
  }
  
  
  return 0;
}
