#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;

  cin >> t;
  int caso = 0;
  while(t--) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    int ans = 0;
    int n = s.size();
    
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        if (s[i] == 'C' and s[i + 1] == 'J') ans += x;
        else if (s[i] == 'J' and s[i + 1] == 'C') ans += y;
      }
    }
    int i = 0, j;
    while (i < n) {
      while (i < n and s[i] != '?') i += 1;
      j = i;
      
      while (j < n and s[j] == '?') j += 1;
      if (i != j and i and j < n) {
        if (s[i - 1] == 'C' and s[j] == 'J') ans += x;
        else if(s[i - 1] == 'J' and s[j] == 'C') ans += y;
      }
      i = j;
    }
    cout << "Case #" << ++caso << ": " << ans << '\n';
  }

  return 0;
}