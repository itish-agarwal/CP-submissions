
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

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

//ABCDEFGHIJKLMNOPQRSTUVWXYZ

const int nax = 1e6 + 66;
int n, q;

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
    t[id] = t[2*id] + t[2*id+1];
  }
  int query(int id, int l, int r, int lq, int rq) {
    if(lq>r || l>rq) {
      return 0;
    }
    if(lq<=l && r<=rq) {
      return t[id];
    }
    int mid = (l+r)/2;
    return query(2*id, l, mid, lq, rq) + query(2*id+1, mid+1, r, lq, rq);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q;
  vector<int> a(n);
  segtree t1(n), t2(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] % 2) {
      t1.update(1, 0, n-1, i, a[i]);
    } else {
      t2.update(1, 0, n-1, i, a[i]);
    }
  }
  
  while(q--) {
    int op;
    cin >> op;
    if(op == 1) {
      int i, inc;
      cin >> i >> inc;
      --i;
      if(a[i] % 2) {
        if((a[i]+inc) % 2) {
          t1.update(1, 0, n-1, i, a[i]+inc);
        } else {
          t1.update(1, 0, n-1, i, 0);
          t2.update(1, 0, n-1, i, a[i]+inc);
        }
      } else {
        if((a[i]+inc) % 2) {
          t2.update(1, 0, n-1, i, 0);
          t1.update(1, 0, n-1, i, a[i]+inc);
        } else {
          t2.update(1, 0, n-1, i, a[i]+inc);
        }
      }
      a[i] += inc;
    } else {
      int l, r, parity;
      cin >> l >> r >> parity;
      --l;
      --r;
      if(parity == 1) {
        cout << t1.query(1, 0, n-1, l, r) << '\n';
      } else {
        cout << t2.query(1, 0, n-1, l, r) << '\n';
      }
    }
  }
  return 0;
}
