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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    int ans = 2e18 + 7;
    for(int i = 0; i <= n-k; i++) {
      ans = min(ans, a[i+k-1] - a[i]);
    }
    cout << ans << '\n';
  }
}
