#include <bits/stdc++.h>

using namespace std;
const int nax = 5e5 + 555;

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
    int mid = (l+r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    t[id] = max(t[2*id], t[2*id+1]);
  }
  int query(int id, int l, int r, int k) {
    //first element in range [lq, rq] >= k;
    if(l == r) {
      return l;
    }
    if(t[id] < k) {
      return -1;
    }
    int mid = (l+r)/2;
    if(t[2*id] >= k) {
      return query(2*id, l,  mid, k);
    }
    return query(2*id+1, mid+1, r, k);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  segtree tree(n);
  for(int i = 0; i < n; i++) {
    tree.update(1, 0, n-1, i, a[i]);
  }
  int answer = n;
  for(int i = n-2; i >= 0; i--) {
    int in = tree.query(1, 0, n-1, 2*a[i]);
    if(in > -1) {
      answer--;
      tree.update(1, 0, n-1, in, 0);
      tree.update(1, 0, n-1, i, 0);
    }
  }
  cout << answer << '\n';
  return 0;
}
