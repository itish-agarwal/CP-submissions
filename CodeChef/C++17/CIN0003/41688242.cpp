#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int nax = 1e4 + 444;
vector<vector<int>> g(nax);
vector<bool> vis(nax);
int n, m, A, B;

int dfs(int u) {
  if(vis[u]) return 0;
  int res = 1;
  vis[u] = 1;
  for(int v : g[u]) {
    res += dfs(v);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> A >> B;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<int> a;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      a.emplace_back(dfs(i));
    }
  }
  n = a.size();
  if(A >= B) {
    cout << (n-1)*B + A << '\n';
  } else {
    //B >= A;
    cout << n*A << '\n';
  }
  return 0;
}

