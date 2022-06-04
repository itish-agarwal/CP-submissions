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
    vector<pair<int, int>> ret;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ret.emplace_back(x, i);
    }
    sort(ret.begin(), ret.end());
    int ans = 0, l = 0;
    for(auto it : ret) {
      int in = it.second;
      ans += abs(l - in);
      l = in;
    }
    cout << ans << '\n';
  }
  return 0;
}
