#include <bits/stdc++.h>

using namespace std;

int main()
{
  char str[10010];
  
  while(scanf("%s", str) != EOF){
    stack<char> s;
    
    int n = strlen(str);
    s.push(str[0]);
    int res = 0;
    for(int i = 1; i < n; i++){
      if(str[i] == 'C'){
        if(!s.empty() && s.top() == 'F'){
          res++;
          s.pop();
        } else{
          s.push('C');
        }
      } else if(str[i] == 'F'){
          if(!s.empty() && s.top() == 'C'){
            res++;
            s.pop();
          } else{
            s.push('F');
          }        
        } else if(str[i] == 'B') {
            if(!s.empty() && s.top() == 'S'){
              res++;
              s.pop();
            } else{
              s.push('B');
            }
          } else if(str[i] == 'S'){
              if(!s.empty() && s.top() == 'B'){
                res++;
                s.pop();
              } else{
                s.push('S');
              }
            }
    }
    
    printf("%d\n", res);
  }
  
  
  return 0;
}
