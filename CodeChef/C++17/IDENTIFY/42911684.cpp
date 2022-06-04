#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t;
    cin >> s >> t;
    vector<int> ans;
    int n = s.size(), m = t.size();
    for(int i = 0; i <= n-m; ++i) {
      int d = 0;
      for(int j = 0; j < m; ++j) {
        if(s[i+j] != t[j]) {
          ++d;
        }
      }
      if(d <= 1) {
        cout << i << " ";
        ans.emplace_back(i);
      }
    }
    if(ans.empty()) {
      cout << "No Match!";
    }
    cout << '\n';
  }
}
