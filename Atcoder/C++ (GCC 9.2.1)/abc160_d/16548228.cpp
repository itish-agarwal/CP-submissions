#include <bits/stdc++.h>

using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  int from = min(x, y);
  int to = max(x, y);
  vector<int> ans(n);
  for(int a = 1; a <= n; a++) {
    for(int b = a+1; b <= n; b++) {
      int dist = b-a;
      int pos = abs(a-x) + abs(b-y) + 1;
      ans[min(dist, pos)]++;
    }
  }
  for(int k = 1; k < n; k++) {
    cout << ans[k] << '\n';
  }
  return 0;
}
