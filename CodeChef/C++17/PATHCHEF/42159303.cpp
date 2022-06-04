#include <bits/stdc++.h>

using namespace std;
#define int long long 

vector<vector<int>> g;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  g.resize(n + 1);
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = 0;
  for(int i = 1; i <= n; i++) {
    const int inf = 2e9 + 777;
    vector<int> dist(n + 1, inf);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v : g[u]) {
        if(dist[v] >= inf) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    int pos = 0;
    for(int i = 1; i <= n; i++) {
      pos = max(pos, dist[i]);
    }
    l = max(l, pos);
  }
  if(k >= l) {
    cout << "0\n";
  } else {
    cout << l - k << '\n';
  }
  return 0;
}
