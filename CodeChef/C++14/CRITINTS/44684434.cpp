#include <bits/stdc++.h>

using namespace std;
const int nax = 507;

vector<vector<int>> g(nax);
vector<bool> vis(nax);

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = true;
  for(auto v : g[u]) {
    dfs(v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int>> edges;
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<int> answer;
  for(int node = 1; node <= n; node++) {
    for(int i = 0; i <= n; ++i) {
      g[i].clear();
      vis[i] = false;
    }
    for(auto it : edges) {
      int u = get<0>(it), v = get<1>(it);
      if(u!=node && v!=node) {
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    int c = 0;
    for(int i = 1; i <= n; ++i) {
      if(!vis[i]) {
        c++;
        dfs(i);
      }
    }
    if(c > 2) {
      answer.push_back(node);
    }
  }
  cout << (int)answer.size() << '\n';
  for(auto it : answer) cout << it << '\n';
  return 0;
}