//@Author: Vinícius Resende. 09/12/2017 - 10:09:32
#include <bits/stdc++.h>

using namespace std;
const int N = 50001;
int v[N];
int l[N];
int r[N];
int ans[N];
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }
  l[0] = r[n - 1] = 1;
  for(int i = 1; i < n; i++){
    l[i] = min(l[i - 1] + 1, v[i]);
  }
  for(int i = n - 2; i >= 0; i--){
    r[i] = min(r[i + 1] + 1, v[i]);
  }
  int x = 0;
  for(int i = 0; i < n; i++){
    ans[i] = min(l[i], r[i]);
    x = max(ans[i], x);
  }
  printf("%d\n", x);
  return 0;
}
