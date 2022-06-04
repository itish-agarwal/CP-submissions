#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 7;
vector<vector<int>> g(nax);
const int MAXLOG = 30;
int par[nax][MAXLOG];
int h[nax], a[nax], pre[nax];

void dfs_h(int v, int p = -1) {
  par[v][0] = p;
  if(p + 1) h[v] = h[p] + 1;
  for(int i = 1; i < MAXLOG; ++i) {
    if(par[v][i-1] + 1) {
      par[v][i] = par[par[v][i-1]][i-1];
    }
  }
  for(auto u : g[v]) {
    if(u != p) {
      dfs_h(u, v);
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
void dfs(int u, int p, int carry) {
  pre[u] = a[u] + carry;
  carry = pre[u];
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u, carry);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, K;
  cin >> n >> K;
  vector<pair<int, int>> edges;
  for(int i = 1; i < n; ++i) {
    int from, to;
    cin >> from >> to;
    edges.emplace_back(from, to);
    g[from].emplace_back(to);
    g[to].emplace_back(from);
  }
  dfs_h(1, -1);
  for(auto it : edges) {
    if(h[it.second] < h[it.first]) {
      a[it.first] = 1;
    }
  }
  dfs(1, -1, 0);
  int q;
  cin >> q;
  while(q--) {
    int from, to;
    cin >> from >> to;
    int lca = LCA(from, to);
    int rev = h[from] - h[lca] - pre[from] + pre[lca];
    int answer = rev * K;
    
    rev = pre[to] - pre[lca];
    answer += rev * K;
    
    //cout << from << " " << to << "  "<< rev <<'\n';    
    cout << answer << '\n';
    
  }
}
