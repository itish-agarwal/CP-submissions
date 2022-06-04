#include <bits/stdc++.h>

using namespace std;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    //TODO: Initialise tree with correct default values
    t.resize(4*_n);
  }
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = val;
      return;
    }

    int mid = (l + r)/2;

    if(pos <= mid) 
      update(2*id, l, mid, pos, val);
    else
      update(2*id+1, mid+1, r, pos, val);
    //TODO: Update t[id] here;
    t[id] = max(t[2*id], t[2*id+1]);
  }
  //TODO: Change return type of query if needed
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) 
      return 0; //TODO: Set this value

    if(lq <= l && r <= rq) 
      return t[id];
    
    int mid = (l + r)/2;

    int ll = query(2*id, l, mid, lq, rq);
    int rr = query(2*id+1, mid+1, r, lq, rq);
    
    return max(ll, rr);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int N, D;
    cin >> N >> D;

    vector<int> p(N);
    for(int i = 0; i < N; ++i) 
      cin >> p[i];

    vector<int> s(N);
    for(int i = 0; i < N; ++i) 
      cin >> s[i];

    vector<int> d(N);
    iota(d.begin(), d.end(), 0);

    sort(d.begin(), d.end(), [&](int i, int j) {
      return p[i] < p[j];
    });

    vector<int> P(N), S(N);
    for(int i = 0; i < N; ++i) {
      P[i] = p[d[i]];
      S[i] = s[d[i]];
    }
    
    segtree tree(N);
    for(int i = 0; i < N; ++i) {
      tree.update(1, 0, N - 1, i, S[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; ++i) {
      if(P[i] <= D) {
        ans = max(ans, S[i]);
        int rem = D - P[i];
        int in = upper_bound(P.begin(), P.end(), rem) - P.begin() - 1;
        if(in > i && in < N) {
          ans = max(ans, S[i] + tree.query(1, 0, N - 1, i + 1, in));
        }
      }
    }

    cout << ans << '\n';
  }
}