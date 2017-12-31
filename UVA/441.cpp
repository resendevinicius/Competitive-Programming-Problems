#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int v[N];
int n;
vector<int> ans;
void backtracking(int i){
  if(ans.size() == 6){
    for(int k = 0; k < 6; k++){
      if(k) printf(" ");
      printf("%d", ans[k]);
    }
    puts("");
    return;
  }
  for(; i < n; i++){
    ans.push_back(v[i]);
    backtracking(i + 1);
    ans.pop_back();
  }
}
int main(){
  int caso = 0;
  while(scanf("%d",&n) == 1 &&  n){
    if(caso++) puts("");
    for(int i = 0; i < n; i++){
      scanf("%d",&v[i]);
    }
    backtracking(0);
    ans.clear();
  }
  return 0;
}
