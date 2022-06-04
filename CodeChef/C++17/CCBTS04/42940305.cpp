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
    vector<pair<int, int>> ret(n);
    for(int i = 0; i < n; ++i) {
      cin >> ret[i].first;
    }
    for(int i = 0; i < n; ++i) {
      cin >> ret[i].second;
    }
    //sort(ret.begin(), ret.end());
    //sorted by heights;
    int ans = 1;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i) {
      for(int j = 0; j < i; ++j) {
        if(ret[i].first > ret[j].first && ret[i].second < ret[j].second) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
  }
}
