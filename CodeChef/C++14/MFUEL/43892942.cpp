#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& it : a ) cin >> it;
    vector<int> dp(n);
    dp[0] = a[0];
    for(int i = 1; i < n; ++i) {
      dp[i] = a[i] + max(0, dp[i-1]);
    }
    int ans = -2e9 - 7;
    for(int x : dp) ans = max(ans, x);
    cout << ans << '\n';
  }  
}
