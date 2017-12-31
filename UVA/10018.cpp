#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int digits[20];
int k;


ll f(ll x){
  k = 0;
  while(x){
    digits[k++] = (x % 10);
    x /= 10;
  }
  ll a = 0;
  ll b = 0;
  for(int i = 0; i < k; i++){
    a *= 10l;
    a += digits[i];
  }
  for(int i = k - 1; i >= 0; i--){
    b *= 10l;
    b += digits[i];
  }
  
  return a + b;
}
int calls;
ll solve(ll x){
  
  ll n = f(x);
  ll copy = n;
  k = 0;
  while(n){
    digits[k++] = (n % 10);
    n /= 10;
  }
  bool ok = true;
  for(int i = 0, j = k - 1; i < j; i++, j--){
    if(digits[i] != digits[j]){
      ok = false;
      break;
    }
  }
  calls++;
  return ok ? copy : solve(copy);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  while(n--){
    ll x;
    cin >> x;
    calls = 0;
    ll ans = solve(x);
    cout << calls << " " << ans << endl;
  }
  
  return 0;
}
