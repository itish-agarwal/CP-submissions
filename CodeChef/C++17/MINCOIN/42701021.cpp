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
  int n;
  cin >> n;
  vector<int> dp(n+1, 0);
  dp[1] = dp[5] = dp[10] = 1;
  for(int i = 2; i <= n; ++i) {
    if(!dp[i]) {
      dp[i] = 1 + dp[i-1];
      if(i-5 >= 0) {
        dp[i] = min(dp[i], 1 + dp[i-5]);
      }
      if(i-10 >= 0) {
        dp[i] = min(dp[i], 1 + dp[i-10]);
      }
    }
  }
  cout << dp[n] << '\n';
}
