#include <bits/stdc++.h>

using namespace std;
#define int int64_t
int n;

vector<pair<int, int>> edges;
vector<vector<int>> g;
vector<int> score, depth;

void dfs(int u, int par, int pre) {
  if((int)g[u].size()==1 && g[u][0]==par) {
    score[u] += pre;
    return;
  }
  score[u] += pre;
  pre = score[u];
  for(int v : g[u]) {
    if(v!=par) {
      dfs(v, u, pre);
    }
  }
  return;
}
void dfh(int u, int par, int d) {
  depth[u] = d;
  for(int v : g[u]) {
    if(v!=par) {
      dfh(v, u, d + 1);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  g.resize(n+2);
  score.resize(n+2);
  depth.resize(n+2);
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back(make_pair(u, v));
  }
  dfh(1, -1, 0);
  int q;
  cin >> q;
  while(q--) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;
    if(t == 1) {
      int u = edges[e].first;
      int v = edges[e].second;
      //minus from v;
      if(depth[v] > depth[u]) {
        score[1] += x;
        score[v] -= x;
      } else {
        score[u] += x;
      }
      //score[v] -= x;
    } else {
      int u = edges[e].first;
      int v = edges[e].second;
      //minus from u;
      if(depth[u] > depth[v]) {
        score[1] += x;
        score[u] -= x;
      } else {
        score[v] += x;
      }
    }
  }
  for(int v : g[1]) {
    dfs(v, 1, score[1]);
  }
  for(int i = 1; i <= n; i++) {
    cout << score[i] << '\n';
  }
  return 0;
}
