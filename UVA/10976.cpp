#include <bits/stdc++.h>

using namespace std;
#define eps 1e-16
int main(){
  int n;
  
  while(scanf("%d",&n) != EOF){
    int j = 1;
    vector<pair<int,int> > v;
    for(int i = n + 1; i <= (n << 1); i++, j++){
      v.push_back(make_pair(i * n / j, i));
    }
    double x = 1. / n;
    vector<pair<int,int> > ans;
    for(int i = 0; i < v.size(); i++){
      if(1. / v[i].first + 1. / v[i].second - x < eps){
        ans.push_back(make_pair(v[i].first, v[i].second));
      }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
      printf("1/%d = 1/%d + 1/%d\n", n, ans[i].first, ans[i].second);
    }
  }
  
  return 0;
}
