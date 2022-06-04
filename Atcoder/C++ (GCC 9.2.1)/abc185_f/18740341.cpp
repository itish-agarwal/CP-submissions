#include <bits/stdc++.h>

using namespace std;
#define int long long 

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}

const int nax = 3e5 + 5577;

struct segtree {
  vector<int> t;
  segtree(int n = nax) {
    t.resize(4*n);
  }
  
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] ^= val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    t[id] = t[2*id] ^ t[2*id + 1];
  }
  
  int query(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) {
      return 0; 
    }
    if(lq<=l && r<=rq) {
      return t[id];
    }
    int mid = (l + r)/2;
    return query(2*id, l, mid, lq, rq) ^ query(2*id+1, mid+1, r, lq, rq);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, q;
  cin >> n >> q;
  segtree tree(n);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree.update(1, 0, n-1, i, x);
  }
  
  while(q--) {
    int T;
    cin >> T;
    if(T == 1) {
      int i, val;
      cin >> i >> val;
      --i;
      tree.update(1, 0, n-1, i, val);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << tree.query(1, 0, n-1, l, r) << '\n';
    }
  }
  return 0;
}
