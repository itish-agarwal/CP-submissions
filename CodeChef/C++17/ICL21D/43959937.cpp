#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(auto v : g[u]) {
    dfs(v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, f;
  cin >> n >> f;
  g.resize(n + 1);
  vis.resize(n + 1);
  while(f--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = -1;
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) {
      ++ans;
      dfs(i);
    }
  }
  cout << ans << '\n';  
}
