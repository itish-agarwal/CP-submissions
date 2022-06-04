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
    int n, x;
    cin >> n;
    vector<int> cnt(n+2);
    int ans = 0;
    while(n--) {
      cin >> x;
      cnt[x]++;
      ans = max(ans, cnt[x]);
    }
    cout << ans << '\n';
  }
  return 0;
}
    