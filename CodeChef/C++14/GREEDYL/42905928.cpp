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
    int ans = 0;
    for(int i = 1; i <= k; ++i) {
      ans = max(ans, n % i);
    }
    cout << ans << '\n';
  }
}
