#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long int t;
  scanf("%llu",&t);
  while(t--){
    unsigned long long int s, d;
    scanf("%llu %llu",&s,&d);
    unsigned long long int a = (s + d) >> 1ull;
    unsigned long long int b = s - a;
    if(s < d || a + b != s || a - b != d){
      puts("impossible");
    } else {
      printf("%llu %llu\n", max(a, b), min(a,b));
    }
  }
  
  return 0;
}
