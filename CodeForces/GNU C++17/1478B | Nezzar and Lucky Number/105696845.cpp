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
    int q, d;
    cin >> q >> d;
    vector<bool> dp(105, 0);
    vector<int> a;
    for(int i = 1; i <= 100; i++) {
      bool ok = 0;
      string s = to_string(i);
      for(char ch : s) {
        if(ch == char('0'+d)) {
          ok = 1;
          break;
        }
      }
      if(ok) a.emplace_back(i);
    }
    dp[d] = 1;
    for(int i = d + 1; i < 105; i++) {
      for(int x : a) {
        dp[x] = 1;
        if(i-x>=0 && dp[i-x]) {
          dp[i] = 1;
          break;
        }
      }
    }
    while(q--) {
      int x;
      cin >> x;
      if(x >= 100) {
        cout << "YES\n";
      } else {
        if(dp[x]) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
  }
  return 0;
}
        
     