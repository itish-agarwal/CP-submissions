#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int res = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i]!=t[i]) {
      ++res;
    }
  }
  cout << res << '\n';
  return 0;
}
