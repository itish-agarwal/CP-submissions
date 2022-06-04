#include <bits/stdc++.h>

using namespace std;
const int nax = 2e5 + 7;
vector<vector<int>> g;

const int MAXLOG = 50;
int par[nax][MAXLOG];
int h[nax];

void dfs(int v, int p = -1) {
  par[v][0] = p;
  if(p + 1) h[v] = h[p] + 1;
  for(int i = 1; i < MAXLOG; ++i) {
    if(par[v][i-1] + 1) {
      par[v][i] = par[par[v][i-1]][i-1];
    }
  }
  for(auto u : g[v]) {
    if(u != p) {
      dfs(u, v);
    }
  }
}

int LCA(int v, int u) {
  if(h[v] < h[u]) swap(v, u);
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] + 1 && h[par[v][i]] >= h[u]) {
      v = par[v][i];
    }
  }
  //now h[v] == h[u];
  if(v == u) return v;
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] - par[u][i]) {
      v = par[v][i];
      u = par[u][i];
    }
  }
  return par[v][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, lca;
  cin >> n;
  g.resize(n + 2);
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(h, 0, sizeof(h));
  memset(par, -1, sizeof(par));
  dfs(1, -1);
  int q;
  cin >> q;
  while(q--) {
    int r, u, v;
    cin >> r >> u >> v;
    int l1 = LCA(r, u);
    int l2 = LCA(r, v);
    int l3 = LCA(u, v);
    if(l1==l2) lca = l3;
    else if(l2==l3) lca = l1;
    else lca = l2;
    cout << lca << '\n';
  }
  return 0;
}
