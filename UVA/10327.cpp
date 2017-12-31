#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int v[N];
int merge(int l, int r){
  int ans = 0;
  if(r > l){
    int mid = (l + r) >> 1;
    ans += merge(l, mid);
    ans += merge(mid + 1, r);
    int a[r + 1];
    int b[r + 1];
    for(int i = l; i <= mid; i++){
      a[i] = v[i];
    }
    for(int i = mid + 1; i <= r; i++){
      b[i] = v[i];
    }
    int i, j;
    int k = l;
    for(i = l, j = mid + 1; i <= mid && j <= r; k++){
      if(a[i] <= b[j]){
        v[k] = a[i++];
      } else {
        ans += (j - k);
        v[k] = b[j++];
      }
    }
    for(int x = i; x <= mid; x++){
      v[k++] = a[x];
    }
    for(int x = j; x <= r; x++){
      v[k++] = b[x];
    }
  }
  return ans;
}

int main(){
  int n;
  while(scanf("%d",&n) != EOF){
    for(int i = 0; i < n; i++){
      scanf("%d",&v[i]);
    }
    printf("Minimum exchange operations : %d\n", merge(0,n - 1));
  }
  
  return 0;
}
