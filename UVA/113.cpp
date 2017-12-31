#include <bits/stdc++.h>

using namespace std;

int main(){
  
  double n, p;
  cout << fixed << setprecision(0);
  while(cin >> n >> p){
    cout << pow(p, 1 / n) << endl;
  }
  
  return 0;
}
