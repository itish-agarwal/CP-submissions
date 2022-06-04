#include <bits/stdc++.h>

using namespace std;
const int INF = (int) 2e9 + 7;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    //TODO: Initialise tree with correct default values
    t.assign(4*_n, INF);
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
    t[id] = min(t[2*id], t[2*id+1]);
  }
  //TODO: Change return type of query if needed
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) 
      return INF;//TODO: Set this value

    if(lq <= l && r <= rq) 
      return t[id];
    
    int mid = (l + r)/2;

    int ll = query(2*id, l, mid, lq, rq);
    int rr = query(2*id+1, mid+1, r, lq, rq);
    
    return min(ll, rr);//merge(L, R);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;

  while(T--) {
    int N, K;
    cin >> N >> K;

    vector<int> H(N + 1);
    for(int i = 0; i < N; ++i) 
      cin >> H[i];

    vector<int> dp(N + 2, INF);
    dp[N + 1] = dp[N] = 0;

    segtree tree(N + 2);

    tree.update(1, 0, N + 1, N + 1, 0);
    tree.update(1, 0, N + 1, N, 0);

    for(int i = N - 1; i >= 0; --i) {
      dp[i] = H[i] + dp[i + 1];
      dp[i] = min(dp[i], tree.query(1, 0, N + 1, i + 1, min(N, i + K)));
      tree.update(1, 0, N + 1, i, H[i] + dp[i+1]);
    }

    cout << dp[0] << '\n';
  }
}