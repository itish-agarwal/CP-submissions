#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    t.resize(4*_n);
  }
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    t[id] = t[2*id]^t[2*id+1];
  }
  int query(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) return 0;
    if(lq<=l && r<=rq) return t[id];
    int mid = (l + r)/2;
    return query(2*id, l, mid, lq, rq) ^ query(2*id+1, mid+1, r, lq, rq);
  }
};

const int nax = 1e5 + 7;
vector<vector<int>> g;
vector<int> euler, start, en;
int depth[nax], vis[nax], par[nax];
vector<pair<int, pair<int, int>>> edges;

void dfs_h(int a, int parent) {
  par[a] = parent;
  if(parent != -1) depth[a] = depth[parent] + 1;
  for(auto b : g[a]) {
    if(b != parent) {
      dfs_h(b, a);
    }
  }
} 
void dfs(int a, int parent) {
  euler.push_back(a);
  vis[a] = 1;
  for(auto b : g[a]) {
    if(b != parent && !vis[b]) {
      dfs(b, a);
    }
  }
  euler.push_back(a);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  g.resize(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, {v, w}});
  }
  //root the tree at 0;
  dfs_h(0, -1);
  for(auto& it : edges) {
    int u = it.first;
    int v = it.second.first;
    if(depth[u] > depth[v]) {
      swap(it.first, it.second.first);
    }
  }
  start.assign(n+1, -1);
  en.assign(n+1, -1);
  dfs(0, -1);
  int k = n + n;
  for(int i = 0; i < k; ++i) {
    if(start[euler[i]] <= -1) {
      start[euler[i]] = i;
    } else {
      en[euler[i]] = i;
    }
  }
  vector<int> b(k);
  segtree tree(k);
  for(auto it : edges) {
    int u = it.first;
    int v = it.second.first;
    int w = it.second.second;
    //parent of v is u
    tree.update(1, 0, k - 1, start[v], w);
    tree.update(1, 0, k - 1, en[v], w);
  }
  int q;
  cin >> q;
  while(q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      int up = edges[x].first;
      int down = edges[x].second.first;
      edges[x].second.second = y;
      //b[start[down]] = b[en[down]] = y;
      tree.update(1, 0, k - 1, start[down], y);
      tree.update(1, 0, k - 1, en[down], y);
    } else {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      //print xor of path between u and v
      int k0 = tree.query(1, 0, k - 1, 0, start[u]);
      int k1 = tree.query(1, 0, k - 1, 0, start[v]);
      cout << (k0^k1) << '\n';
    }
  }
  return 0;
}
