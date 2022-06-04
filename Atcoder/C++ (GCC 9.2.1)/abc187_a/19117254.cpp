#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> ret(n);
  for(int i = 0; i < n; i++) {
    cin >> ret[i].first >> ret[i].second;
  }
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      int x1 = ret[i].first, y1 = ret[i].second;
      int x2 = ret[j].first, y2 = ret[j].second;
      bool A = ((y2-y1)*(x2-x1) <= (x2-x1)*(x2-x1));
      bool B = ((y2-y1)*(x2-x1) >= (x1-x2)*(x2-x1));
      ans += (A && B);
    }
  }
  cout << ans << '\n';
  return 0;
}
