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
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    vector<int> dp(n);
    dp[0] = a[0];
    int ans = a[0];
    for(int i = 1; i < n; ++i) {
      dp[i] = a[i];
      for(int j = 0; j < i; ++j) {
        if(a[j] < a[i]) {
          dp[i] = max(dp[i], a[i] + dp[j]);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
