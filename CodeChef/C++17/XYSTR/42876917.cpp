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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1);
    for(int i = n-2; i >= 0; --i) {
      dp[i] = dp[i+1];
      if(s[i] != s[i+1]) {
        dp[i] = max(dp[i], 1 + dp[i+2]);
      }
    }
    cout << dp[0] << '\n';
  }
}
