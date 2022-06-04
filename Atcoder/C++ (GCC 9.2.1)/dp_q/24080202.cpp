#include <bits/stdc++.h>

using namespace std;
#define int long long
struct segtree {
  vector<int> t;
  segtree(int _n) {
    //initialise t
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
    //update t[id] here;
    t[id] = max(t[2*id], t[2*id+1]);
  }
  //change return type of query if wanted
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) return 0; //see to this
    if(lq <= l && r <= rq) return t[id];
    int mid = (l + r)/2;
    int ll = query(2*id, l, mid, lq, rq);
    int rr = query(2*id+1, mid+1, r, lq, rq);
    return max(ll, rr);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n), a(n);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    h[i]--;
  }
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  segtree tree(n);
  for(int i = 0; i < n; i++) {
    int l = 0, r = h[i] - 1;
    if(r >= l) {
      int best = a[i] + tree.query(1, 0, n - 1, l, r);
      tree.update(1, 0, n - 1, h[i], best);
      ans = max(ans, best);
    } else {
      tree.update(1, 0, n - 1, h[i], a[i]);
      ans = max(ans, a[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}