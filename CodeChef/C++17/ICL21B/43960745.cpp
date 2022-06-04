#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
vector<vector<int>> g;
vector<int> a, dp, sum, par;

void dfs(int u, int p) {
  if((int) g[u].size()==1 && g[u][0]==p) {
    dp[u] = a[u];
    return;
  }
  int mx = 0;
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u);
      mx = max(mx, dp[v]);
    }
  }
  dp[u] = a[u] + mx;
}
void dfss(int u, int p, int s) {
  sum[u] = s;
  for(auto v : g[u]) {
    if(v != p) {
      dfss(v, u, s + a[v]);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  a.resize(n + 1);
  dp.resize(n + 1);
  par.resize(n + 1);
  sum.resize(n + 1);
  for(int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    par[i] = p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dfs(0, -1);
  dfss(0, -1, a[0]);
  int ans = a[0];
  for(int i = 0; i < n; ++i) {
    multiset<pair<int, int>> c;
    for(auto v : g[i]) {
      if(v != par[i]) {
        c.insert({-dp[v], v});
      }
    }
    for(auto v : g[i]) {
      if(v != par[i]) {
        int pos = sum[i] + a[v];
        c.erase(c.find({-dp[v], v}));
        if(!c.empty()) {
          auto it = *c.begin();
          pos -= it.first;
        }
        c.insert({-dp[v], v});
        ans = max(ans, pos);
      }
    }
  }
  cout << ans << '\n';
}
