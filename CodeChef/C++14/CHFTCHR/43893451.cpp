#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

bool same(string s, string t ) {
  if((int)s.size() == (int)t.size()) {
    int d = 0;
    for(int i = 0; i < (int)s.size(); ++i) {
      if(s[i] != t[i]) {
        ++d;
      }
    }
    return d <= 1;
  }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(auto& it : a ) cin >> it;
    for(auto& it : b ) cin >> it;
    for(string s : b) {
      bool ok = 0;
      for(string t : a) {
        if(same(s, t)) {
          ok = 1;
          break;
        }
      }
      cout << ok << " ";
    }
    cout << '\n';
  }
}
