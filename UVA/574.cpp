#include <bits/stdc++.h>

using namespace std;
int n, k;

const int N = 15;

int v[N];
int pd[N][N * 1000];

bool f(int i, int sum){
  if(sum < 0) return false;
  if(sum == 0) return true;
  if(i == n) {
    return false;
  }
  if(pd[i][sum] != -1) return pd[i][sum];
  bool ans = f(i + 1, sum);
  ans |= f(i + 1, sum - v[i]);
  return pd[i][sum] = ans;
}
vector<int> ans;
void rec(int i, int sum){
  if(sum < 0) return;
  if(i == n){
    return;
  }
  if(f(i + 1, sum - v[i])){
    ans.push_back(v[i]);
    rec(i + 1, sum - v[i]);
  } else if(f(i + 1, sum)){
    rec(i + 1, sum);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  while(cin >> k >> n, k | n){
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    memset(pd,-1,sizeof pd);
    bool ok = f(0, k);
    cout << "Sums of " << k << ":" << endl;
    vector<int> last;
    if(ok){
      for(int i = 0; i < n; i++){
        rec(i, k);
        if(ans.size() > 0 && ans != last){
          for(int j = 0; j < ans.size(); ++j){
            if(j) cout << "+";
            cout << ans[j];
          }
          cout << endl;
        }
        last = ans;
        ans.clear();
      }
    } else {
      cout << "NONE" << endl;
    }
  }
  
  return 0;
}
