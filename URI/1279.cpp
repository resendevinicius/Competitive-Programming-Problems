#include <bits/stdc++.h>

using namespace std;

int main(){
  
  
  char s[10010];
  bool ok = false;
  while(scanf("%s", s) != EOF){
    
    if(ok){
      puts("");
    }
    ok = true;
    
    int n = strlen(s);
    int d4, d15, d55, d100, d400;
    d4 = d15 = d55 = d100 = d400 = 0;
    for(int i = 0; i < n; i++){
      d4 *= 10;
      d15 *= 10;
      d55 *= 10;
      d100 *= 10;
      d400 *= 10;
      d4 += (s[i] - '0');
      d15 += (s[i] - '0');
      d55 += (s[i] - '0');
      d100 += (s[i] - '0');
      d400 += (s[i] - '0');
      d4 %= 4;
      d15 %= 15;
      d55 %= 55;
      d100 %= 100;
      d400 %= 400;
    }
    bool a,b,c;
    a = b = c = false;
    if(d4 == 0 && d100 != 0 || d400 == 0){
      a = true;
      if(d55 == 0){
        c = true;
      }
    } 
    if(d15 == 0){
      b = true;
    }
    
    if(a){
      puts("This is leap year.");
    }
    if(b){
      puts("This is huluculu festival year.");
    }
    if(c){
      puts("This is bulukulu festival year.");
    }
    if(!a && !b && !c){
      puts("This is an ordinary year.");
    }

  }
  
  return 0;
}
