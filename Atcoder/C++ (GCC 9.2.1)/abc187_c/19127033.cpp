#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<string> s0, s1;
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if(s[0] == '!') {
      s1.insert(s.substr(1));
    } else {
      s0.insert(s);
    }
  }
  for(string s : s0) {
    if(s1.find(s)!=s1.end()) {
      cout << s << '\n';
      return 0;
    }
  }
  cout << "satisfiable\n";
  return 0;
}
