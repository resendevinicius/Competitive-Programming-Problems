#include <bits/stdc++.h>

using namespace std;
int v[333];

int convert(string s){
  int ans = 0;
    
  for(int i = 2; i < s.size(); i++){
    ans *= 16;
    ans += v[tolower(s[i])];
  }
  
  return ans;
}


int main(){
  
  char str[10010];
  int res;
  int start = 10;
  for(int i = 'a'; i <= 'f'; i++){
    v[i] = start++;
  }
  for(int i = '0'; i <= '9'; i++){
    v[i] = i - '0';
  }
  
  while(cin >> str){
    string s = (string) str;
    if(s == "-1"){
      exit(0);
    }
    if(s[1] == 'x'){
      printf("%d\n", convert(s));
    } else{
      stringstream ss(s);
      ss >> res;
      printf("0x%X\n", res);
    }
  }
  return 0;
}
