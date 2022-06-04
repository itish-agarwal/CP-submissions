#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  k = m - k;
  //k -> turn on exactly 
  vector<int> affected(m);
  for(int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    affected[i] = n - a;
  }
  vector<tuple<int, int>> ret;
  //if switch is on
  for(int i = 0; i < m; ++i) {
    ret.emplace_back(n - affected[i], i);
  }
  sort(ret.begin(), ret.end());
  reverse(ret.begin(), ret.end());
  int ans = 0;
  for(int i = 0; i < k; i++) {
    ans += get<0>(ret[i]);
  }
  for(int i = k; i < m; ++i) {
    ans += n - get<0>(ret[i]);
  }
  cout << ans << '\n';
}