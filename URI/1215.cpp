#include <bits/stdc++.h>

using namespace std;

int main() {
  string line, all_lines, word = "";
  set<string> ans;
  while (1) {
    char c = getchar();
    if (isalpha(c)) {
      word += tolower(c);
    } else if (c == EOF) {
      if (word.size()) ans.insert(word);
      break;
    } else {
      if(word.size()) ans.insert(word);
      word = "";
    }
  }
  for (auto &u: ans) {
    cout << u << '\n';
  }
  return 0;
}
