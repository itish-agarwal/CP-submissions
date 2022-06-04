#include <bits/stdc++.h>

using namespace std;
#define int int64_t 
const int inf = 1e18 + 555555;
const int mod = 1e9 + 7;

struct node {
  int mini, lsum;
  node(int a = 0, int b = 0) {
    mini = a;
    lsum = b;
  }
};
struct segtree {
  vector<node> t;
  segtree(int n) {
    t.resize(4*n);
  }
  node merge(node a, node b) {
    node ans;
    ans.mini = min(a.mini, b.mini);
    return ans;
  }
  void push(int id, int l, int r) {
    if(t[id].lsum > 0) {
      t[id].mini += t[id].lsum;
      if(l!=r) {
        t[2*id].lsum += t[id].lsum;
        t[2*id+1].lsum += t[id].lsum;
      }
      t[id].lsum = 0;
    }
    return;
  }
  void update(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if(lq>r || l>rq) {
      return;
    }
    if(lq<=l && r<=rq) {
      t[id].lsum += val;
      push(id, l, r);
      return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, lq, rq, val);
    update(2*id+1, mid+1, r, lq, rq, val);
    t[id] = merge(t[2*id], t[2*id+1]);
  }
  int query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if(lq>r || l>rq) {
      return inf;
    }
    if(lq<=l && r<=rq) {
      return t[id].mini;
    }
    int mid = (l+r)/2;
    int x = query(2*id, l, mid, lq, rq);
    int y = query(2*id+1, mid+1, r, lq, rq);
    return min(x, y);
  }
};
signed main(){ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, y;
    cin >> n >> y;
    segtree tree(n);
    for(int i = 0; i < n; i++) {
      tree.update(1, 0, n-1, i, i, 1);
    }
    while(y--) {
      int l, r;
      cin >> l >> r;
      int mn = tree.query(1, 0, n-1, l, r);
      mn = (mn + mod) % mod;
      tree.update(1, 0, n-1, l, r, mn);
    }
    cout << tree.query(1, 0, n-1, 0, n-1) % mod << '\n';
  }
  return 0;
}
