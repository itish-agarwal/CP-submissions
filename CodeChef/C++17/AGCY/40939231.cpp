#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> start(n+2), end(n+2), add(n+2);
  while(q--) {
    int l, r;
    cin >> l >> r;
    start[l]++;
    end[r+1]++;
    add[r+1] += (r-l+2);
  }
  int active = 0, prev = 0;
  for(int i = 1; i <= n; i++) {
    int res = prev + active + start[i] - add[i];
    prev = res;
    cout << res << " ";
    active += start[i];
    active -= end[i];
  }
  cout << '\n';
  return;
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    solve();
  }
}
