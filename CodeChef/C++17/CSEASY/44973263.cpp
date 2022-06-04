#include <bits/stdc++.h>

using namespace std;
const int nax = 30;
vector<vector<int>> g(nax);
vector<bool> vis(nax), in_stack(nax);

bool dfs(int u) {
  if(vis[u]) return 0;
  vis[u] = in_stack[u] = 1;
  for(auto v : g[u]) {
    dfs(v);
    if(vis[v] && in_stack[v]) {
      return true;
    }
  }
  in_stack[u] = 0;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, e;
    cin >> n >> e;
    for(int i = 0; i <= n; i++) {
      g[i].clear();
      vis[i] = in_stack[i] = 0;
    }
    while(e--) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      // g[b].push_back(a);
    }
    bool cycle = 0;
    for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
        cycle |= dfs(i);
      }
    }
    cout << (cycle ? "NO" : "YES") << '\n';
  }
}