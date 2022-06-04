#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int s0 = 0, s1 = 0;
  for(char ch : s) {
    s0 += ch - '0';
  }
  for(char ch : t) {
    s1 += ch - '0';
  }
  cout << max(s0, s1) << '\n';  
  return 0;
}
