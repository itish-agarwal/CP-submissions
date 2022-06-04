#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;
int n, m;

int dfs(int u) {
  if(vis[u]) return 0;
  int res = 1;
  vis[u] = 1;
  for(int v : g[u]) {
    res += dfs(v);
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  g.resize(n+1);
  vis.resize(n+1);
  while(m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> ret;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      ret.push_back(dfs(i));
    }
  }
  n = ret.size();
  vector<int> post(n);
  post.back() = ret.back();
  for(int i = n-2; i >= 0; i--) {
    post[i] = post[i+1] + ret[i];
  }
  long long ans = 0;
  for(int i = 0; i+1 < n; i++) {
    ans += (ll)ret[i]*(ll)post[i+1];
  }
  cout << ans << '\n';
  return 0;
}
