#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g, d;
vector<int> a;

const int nax = 1e5 + 7;
int parent[nax], dp[nax][2];

void dfs(int u, int p) {
  parent[u] = p;
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u);
    }
  }
}
int rec(int u, int take) {
  if(dp[u][take] > -1) return dp[u][take];
  if(take) {
    int ans = a[u];
    for(auto v : g[u]) {
      if(v != parent[u]) {
        ans += rec(v, !take);
      }
    }
    dp[u][take] = ans;
    return ans;
  }
  int ans = 0;
  for(auto v : g[u]) {
    if(v != parent[u]) {
      ans += max(rec(v, !take), rec(v, take));
    }
  }
  dp[u][take] = ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  d.resize(n + 1);
  a.resize(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(dp, -1, sizeof(dp));
  dfs(1, -1);
  cout << max(rec(1, 1), rec(1, 0)) << '\n';
}