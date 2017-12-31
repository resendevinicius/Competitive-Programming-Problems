#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int n, k;
int v[N];
map<vector<int>, bool> solutions;
vector<int> ans;
bool ok;
void back(int i, int sum){
  if(sum < 0) return;
  if(sum == 0 && !solutions.count(ans)) {
    for(int j = 0; j < ans.size(); j++){
      if(j) cout << "+";
      if(ans[j] != 0){
        cout << ans[j];
      }
    }
    cout << endl;
    solutions[ans] = true;
    ok = true;
    return;
  }
  for(; i < n; i++){
    ans.push_back(v[i]);
    back(i + 1, sum - v[i]);
    ans.pop_back();
  }
}

int main(){
  
  while(cin >> k >> n, n | k){
    ok = false;
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    cout << "Sums of " << k << ":" << endl;
    back(0, k);
    if(!ok){
      cout << "NONE" << endl;
    }
    solutions.clear();
  }
  
  
  return 0;
}
