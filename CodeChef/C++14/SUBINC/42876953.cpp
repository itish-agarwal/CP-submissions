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
    dp.back() = 1;
    int ans = 1;
    for(int i = n-2; i >= 0; --i) {
      dp[i] = 1;
      if(a[i] <= a[i+1]) {
        dp[i] += dp[i+1];
      }
      ans += dp[i];
    }
    cout << ans << '\n';
  }
}
