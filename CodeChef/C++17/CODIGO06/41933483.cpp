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
    if(!n) {
      cout << "0\n";
      continue;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> dp(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] == 1) {
        dp[i] = 1;
      }
      if(i > 0 && a[i] > 1 && dp[i-1] > 0 && a[i]==a[i-1] + 1) {
        dp[i] = max(dp[i], dp[i-1] + 1);
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
