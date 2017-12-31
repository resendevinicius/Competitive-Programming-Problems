#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
char s[N];

int main(){
  int n, k;
  while(scanf("%d %d",&n,&k),  n | k){
    scanf(" %s",&s);
    
    stack<char> st;
    
    st.push(s[0]);
    for(int i = 1; s[i] != '\0'; i++){
      while(!st.empty() && s[i] > st.top() && k){
        st.pop();
        k--;
      }
      st.push(s[i]);
    }
    string ans;
    while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int) ans.size() - k; i++){
      printf("%c", ans[i]);
    }
    puts("");
  }
  
  return 0;
}
