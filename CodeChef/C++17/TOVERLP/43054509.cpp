#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ret;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      ret.emplace_back(l, 1);
      ret.emplace_back(r, 2);
    }
    for(int i = 0; i < m; ++i) {
      int l, r;
      cin >> l >> r;
      ret.emplace_back(l, 3);
      ret.emplace_back(r, 4);
    }
    sort(ret.begin(), ret.end());
    int a = 0, b = 0;
    for(int i = 0; i < (int)ret.size(); ++i) {
      if(ret[i].second == 1) ++a;
      else if(ret[i].second == 2) --a;
      else if(ret[i].second == 3) ++b;
      else --b;
      if(i + 1 < (int)ret.size()) {
        ans += a*b*(ret[i+1].first - ret[i].first);
      }
    }
    cout << ans << '\n';
  }
}
