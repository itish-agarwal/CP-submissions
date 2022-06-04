#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int nax = 5e5 + 7;
vector<vector<int>> g;
int n, q, a[nax], add[nax];

void dfs(int u, int parent, int prev) {
  prev += add[u];
  a[u] += prev;
  for(auto v : g[u]) {
    if(v != parent) {
      dfs(v, u, prev);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  g.resize(n + 2);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  while(q--) {
    int node, val;
    cin >> node >> val;
    --node;
    add[node] += val;
  }
  dfs(0, -1, 0);
  for(int i = 0; i < n; ++i) {
    cout << a[i] << " " ;
  }
  cout << '\n';
  return 0;
}
