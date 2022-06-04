#include <bits/stdc++.h>

using namespace std;
#define int int64_t 
const int nax = 1e5 + 55;

struct segtree {
  vector<int> t;
  segtree(int n = nax) {
    t.resize(4*n);
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
    t[id] = t[2*id] + t[2*id+1];
  }
  int query(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) {
      return 0;
    }
    if(lq<=l && r<=rq) {
      return t[id];
    }
    int mid = (l + r)/2;
    return query(2*id, l, mid, lq, rq) + query(2*id+1, mid+1, r, lq, rq);
  }
};
signed main(){ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int in = 0;
    segtree tree(n);
    for(int i = 0; i < n; i++) {
      int idx = a[i]-1;
      in += tree.query(1, 0, n-1, idx, n-1);
      tree.update(1, 0, n-1, idx, 1);
    }
    cout << 2*in*x << '\n';
  }
  return 0;
}
