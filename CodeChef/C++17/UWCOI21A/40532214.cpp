
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

vector<int> row, col;
const int nax = 2e5 + 435;

struct segtree {
  vector<vector<int>> t;
  segtree(int n = nax) {
    t.resize(4*n);
  }
  void build(int id, int l, int r) {
    if(l == r) {
      t[id].push_back(row[l]);
      return;
    }
    for(int i = l; i <= r; i++) {
      t[id].push_back(row[i]);
    }
    sort(t[id].begin(), t[id].end());
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
  }
  int query(int id, int l, int r, int lq, int rq, int lower) {
    
    if(lq>r || l>rq) {
      return 0;
    }
    if(lq<=l && r<=rq) {
      int in = lower_bound(t[id].begin(), t[id].end(), lower) - t[id].begin();
      return (int)t[id].size() - in;
    }
    int mid = (l+r)/2;
    return query(2*id, l, mid, lq, rq, lower) + query(2*id+1, mid+1, r, lq, rq, lower);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n ;
    cout << 1 << " " << n << '\n';
  }
  return 0;
}
  
    
    
  
  
