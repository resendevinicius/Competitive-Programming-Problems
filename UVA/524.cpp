#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 50;
vector<int> ans;
vector<int> primes;
int p[N];


void crivo(){
  for(int i = 2; i < N; i++){
    if(!p[i]){
      for(int j = i; j < N; j += i){
        p[j] = 1;
      }
      primes.push_back(i);
    }
  }
}
void back(){
  if(ans.size() == n - 1){
    bool ok = false;
    for(int k = 0; k < primes.size(); k++){
      if(1 + ans.back() == primes[k]){
        ok = true;
        break;
      }
    }
    if(!ok) return;
    cout << 1;
    for(int j = 0; j < ans.size(); j++){
      cout << " " << ans[j];
    }
    cout << endl;      
    return;
  }
  for(int j = 2; j <= n; j++){
    if(find(ans.begin(), ans.end(), j) == ans.end()) {
      bool ok = false;
      for(int k = 0; k < primes.size(); k++){
        if((ans.size() > 0 && ans.back() + j == primes[k]) || (ans.size() == 0 && 1 + j == primes[k])){
          ok = true;
        }
      }
      if(ok){
        ans.push_back(j);
        back();
        ans.pop_back();
      }
    }
  }
}

int main(){
  
  
  int caso = 0;
  crivo();
  while(cin >> n){
    if(caso++) cout << endl;
    cout << "Case " << caso << ":" << endl;
    if(n > 1){
      back();
    }
  }
  
  
  return 0;
}
