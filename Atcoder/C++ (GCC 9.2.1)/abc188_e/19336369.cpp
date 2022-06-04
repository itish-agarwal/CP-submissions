#include <bits/stdc++.h>

using namespace std;
#define int long long

const int nax = 2e5 + 555;
vector<vector<int>> g(nax);
int n, m, a[nax], dp[nax];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while(m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
  }
  dp[n-1] = n-1;
  for(int i = n-2; i >= 0; i--) {
    int ans = i, val = a[i];
    for(int v : g[i]) {
      if(a[dp[v]] > val) {
        val = a[dp[v]];
        ans = dp[v];
      }
    }
    dp[i] = ans;
  }
  int ans = -1e18;
  for(int i = 0; i < n; i++) {
    if(dp[i]!=i) {
      ans = max(ans, a[dp[i]] - a[i]);
    }
  }
  if(ans <= -1e18) {
    for(int i = 0; i < n; i++) {
      for(int v : g[i]) {
        ans = max(ans, a[v] - a[i]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
  
  
