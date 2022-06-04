#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int INF = 2e18 + 7;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    //initialise t
    t.assign(4*_n, INF);
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
    t[id] = min(t[2*id], t[2*id + 1]);
  }
  //change return type of query if wanted
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) return INF;//see to this
    if(lq <= l && r <= rq) return t[id];
    int mid = (l + r)/2;
    int ll = query(2*id, l, mid, lq, rq);
    int rr = query(2*id+1, mid+1, r, lq, rq);
    return min(ll, rr);
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N, M, C;
  cin >> N >> M >> C;

  vector<vector<int>> A(N, vector<int> (M));
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }

  int possible, ans = INF;
  segtree tree(M);

  tree.update(1, 0, M - 1, M - 1, A[N-1][M-1] + C * (N-1 + M-1));

  for(int i = N - 1; i >= 0; --i) {
    for(int j = M - 1; j >= 0; --j) {
      if(i == N - 1 && j == M - 1)
        continue;

      if(i == N - 1) {
        possible = tree.query(1, 0, M - 1, j + 1, M - 1);
        ans = min(ans, possible + A[i][j] - C * (i + j));
        tree.update(1, 0, M - 1, j, A[i][j] + C * (i + j));
        continue;
      }

      if(j == M - 1) {
        possible = tree.query(1, 0, M - 1, j, j);
        ans = min(ans, possible + A[i][j] - C * (i + j));
      }

      possible = tree.query(1, 0, M - 1, j, M - 1);
      ans = min(ans, possible + A[i][j] - C * (i + j));

      int at = tree.query(1, 0, M - 1, j, j);

      at = min(at, A[i][j] + C * (i + j));

      tree.update(1, 0, M - 1, j, at);
    }
  }

  for(int j = 0; j < M; ++j) 
    tree.update(1, 0, M - 1, j, INF);

  tree.update(1, 0, M - 1, 0, A[N-1][0] + C * (N-1));

  for(int i = N - 1; i >= 0; --i) {
    for(int j = 0; j < M; ++j) {
      if(i == N - 1 && j == 0)
        continue;

      if(i == N - 1) {
        possible = tree.query(1, 0, M - 1, 0, j - 1);
        ans = min(ans, possible + A[i][j] + C * (j - i));
        tree.update(1, 0, M - 1, j, A[i][j] + C * (i - j));
        continue;
      }

      if(j == 0) {
        possible = tree.query(1, 0, M - 1, j, j);
        ans = min(ans, possible + A[i][j] + C * (j - i));
      }

      possible = tree.query(1, 0, M - 1, 0, j);
      ans = min(ans, possible + A[i][j] + C * (j - i));

      int at = tree.query(1, 0, M - 1, j, j);

      at = min(at, A[i][j] + C * (i - j));

      tree.update(1, 0, M - 1, j, at);
    }
  }

  cout << ans << '\n';
}
