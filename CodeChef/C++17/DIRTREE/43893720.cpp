#include <bits/stdc++.h>

using namespace std;
const int nax = 1e6 + 7;
vector<vector<int>> g(nax);

const int MAXLOG = 30;
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
  int tt = 1;
  //cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    int n, q;
    cin >> n >> q;
    memset(h, 0, sizeof(h));
    memset(par, -1, sizeof(par));
    for(int i = 0; i <= n; ++i) g[i].clear();
    //for(int i = 1; i <= n; ++i) {
      //int N;
      //cin >> N;
      //while(N--) {
        //int x;
        //cin >> x;
        //g[i].push_back(x);
        //g[x].push_back(i);
      //}
    //}
    for(int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, -1);
    while(q--) {
      int a, b;
      cin >> a >> b;
      if(LCA(a, b) == a) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      //cout << LCA(a, b) << '\n';
    }
  }
  return 0;
}
