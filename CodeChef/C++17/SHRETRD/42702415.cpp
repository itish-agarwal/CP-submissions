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
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for(auto& it : a) cin >> it;
    int mx = a.back();
    int ans = 0;
    for(int i = n-2; i >= 0; --i) {
      dp[i] = dp[i+1];
      dp[i] = max(dp[i], mx - a[i]);
      mx = max(mx, a[i] + dp[i]);
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
