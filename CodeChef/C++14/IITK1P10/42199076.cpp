#include <bits/stdc++.h>

using namespace std;
#define int long long
vector<int> euler, start, en, vis;
vector<vector<int>> g;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    t.resize(4*_n);
  }
  void update(int x, int l, int r, int pos, int val) {
    if(l == r) {
      t[x] = val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*x, l, mid, pos, val);
    } else {
      update(2*x + 1, mid + 1, r, pos, val);
    }
    t[x] = t[x + x] + t[x + x + 1];
  }
  int query(int x, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) return 0;
    if(lq<=l && r<=rq) return t[x];
    int mid = (l + r)/2;
    return query(2*x, l, mid, lq, rq) + query(2*x + 1, mid + 1, r, lq, rq);
  }
};
void dfs(int a, int parent) {
  euler.push_back(a);
  vis[a] = 1;
  for(auto b : g[a]) {
    if(b!=parent && !vis[b]) {
      dfs(b, a);
    }
  }
  euler.push_back(a);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  g.resize(n + 1);
  vis.resize(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  start.assign(n, -1);
  en.assign(n, -1);
  int k = n + n;
  for(int i = 0; i < k; ++i) {
    if(start[euler[i]] <= -1) {
      start[euler[i]] = i;
    } else {
      en[euler[i]] = i;
    }
  }
  segtree tree(k);
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] == 0) {
      int in = start[i];
      tree.update(1, 0, k - 1, in, 1);
    }
  }
  while(q--) {
    char ch;
    cin >> ch;
    if(ch == 'U') {
      int node, val;
      cin >> node >> val;
      --node;
      a[node] += val;
      int in = start[node];
      if(a[node] == 0) {
        tree.update(1, 0, k - 1, in, 1);
      } else {
        tree.update(1, 0, k - 1, in, 0);
      }
    } else {
      int node;
      cin >> node;
      --node;
      int l = start[node], r = en[node];
      cout << tree.query(1, 0, k - 1, l, r) << '\n';
    }
  }
  return 0;
}
