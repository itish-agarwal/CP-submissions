#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> row(h), col(w);
  vector<pair<int, int>> pts(m);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    row[x]++; col[y]++;
    pts[i] = make_pair(x, y);
  }
  int maxr = -1, maxc = -1;
  for(int x : row) {
    maxr = max(maxr, x);
  }
  for(int x : col) {
    maxc = max(maxc, x);
  }
  int r = 0, c = 0, should = 0;
  for(int x : row) {
    if(x==maxr) r++;
  }
  for(int x : col) {
    if(x==maxc) c++;
  }
  for(pair<int, int> p : pts) {
    int x = p.first;
    int y = p.second;
    if(row[x]==maxr && col[y]==maxc) {
      should++;
    }
  }
  if(r*c > should) {
    cout << maxr + maxc << '\n';
  } else {
    cout << maxr + maxc - 1 << '\n';
  }
  return 0;
}
