#include <bits/stdc++.h>


using namespace std;

int mod;

bool impar(int a){
  return (1 & a);
}
bool compare(const int &a, const int &b){
  int c = a % mod;
  int d = b % mod;
  if(c != d){ 
    return c < d;
  } 
  if(!impar(a) && impar(b)){
    return false;
  }
  if(impar(a) && !impar(b)){ 
    return true;
  }
  if(impar(a) && impar(b)){
    return a > b;
  }
  if(!impar(a) && !impar(b)){
    return a < b;
  }
  
}


int main()
{
  int n;
  
  while(scanf("%d %d",&n,&mod), n | mod){
    int v[n];
    for(int i = 0; i < n; i++){
      scanf("%d",&v[i]);
    }

    sort(v, v + n, compare);
    printf("%d %d\n", n, mod);
    for(int i = 0; i < n; i++){
      printf("%d\n", v[i]);
    }
  }
  puts("0 0");
  return 0;
}


