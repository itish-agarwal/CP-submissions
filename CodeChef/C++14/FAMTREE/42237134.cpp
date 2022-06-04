#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
vector<vector<int>> g;
const int nax = 1e5 + 7;
vector<int> a, par;
pair<int, int> p[nax];

//max, min
void dfs(int u, int parent) {
  p[u].first = p[u].second = a[u];
  for(int v : g[u]) {
    if(v != parent) {
      dfs(v, u);
      p[u].first = max(p[u].first, p[v].first);
      p[u].second = min(p[u].second, p[v].second);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  g.resize(n + 1);
  a.resize(n + 1);
  par.resize(n + 1);
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int root = 1;
  for(int i = 1; i <= n; ++i) {
    cin >> par[i];
    if(par[i] == -1) root = i;
    if(par[i] > -1) {
      g[par[i]].push_back(i);
      g[i].push_back(par[i]);
    }
  }
  //for(int i = 1; i < n; ++i) {
    //int u, v;
    //cin >> u >> v;
    //g[u].push_back(v);
    //g[v].push_back(u);
  //}
  dfs(root, -1);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans = max(ans, a[i] - p[i].second);
    ans = max(ans, p[i].first - a[i]);
  }
  cout << ans << '\n';
  return 0;
}
