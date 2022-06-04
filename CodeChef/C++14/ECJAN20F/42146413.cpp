#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

struct segtree {
  vector<int> t;
  segtree(int n) {
    t.resize(4*n);
  }
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] += val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    t[id] = t[2*id] + t[2*id+1];
  }
  int query(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) return 0;
    if(lq<=l && r<=rq) return t[id];
    int mid = (l + r)/2;
    int k0 = query(2*id, l, mid, lq, rq);
    int k1 = query(2*id+1, mid+1, r, lq, rq);
    return k0 + k1;
  }
};

vector<vector<int>> g;
vector<int> euler, a, start, en, vis;

void dfs(int u, int p) {
  euler.emplace_back(u);
  vis[u] = true;
  for(auto v : g[u]) {
    if(v!=p && !vis[v]) {
      dfs(v, u);
    }
  }
  euler.emplace_back(u);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  g.resize(n+1);
  a.resize(n+1);
  vis.resize(n+1);
  start.assign(n+1, -1);
  en.assign(n+1, -1);
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dfs(0, -1);
  int k = n + n;
  for(int i = 0; i < k; i++) {
    if(start[euler[i]] <= -1) {
      start[euler[i]] = i;
    } else {
      en[euler[i]] = i;
    }
  }
  vector<int> b(k);
  for(int i = 0; i < n; i++) {
    b[start[i]] = a[i];
    b[en[i]] = -a[i];
  }
  b[start[0]] = b[en[0]] = 0;
  segtree tree(k);
  for(int i = 0; i < k; i++) {
    tree.update(1, 0, k-1, i, b[i]);
  }
  while(q--) {
    int type;
    cin >> type;
    if(type==1) {
      int node;
      cin >> node;
      --node;
      int r = start[node];
      cout << tree.query(1, 0, k-1, 0, r) << '\n';
    } else {
      int node, val;
      cin >> node >> val;
      --node;
      int st = start[node], ein = en[node];
      if(node > 0) {
        tree.update(1, 0, k-1, st, val);
        tree.update(1, 0, k-1, ein, -val);
      }
    }
  }
  return 0;
}
