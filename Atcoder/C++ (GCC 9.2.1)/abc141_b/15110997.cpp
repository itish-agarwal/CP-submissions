#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  bool ok = 1;
  for(int i = 0; i < n; ++i) {
    if(i & 1) {
      if(s[i] == 'R') {
        ok = 0;
        break;
      }
    } else {
      if(s[i] == 'L') {
        ok = 0;
        break;
      }
    }
  }
  cout << (ok ? "Yes\n" : "No\n");
  return 0;
}
