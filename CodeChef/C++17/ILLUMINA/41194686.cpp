#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    int ans = n * m;
    ans /= __gcd(n, m);
    cout << ans << '\n';
  }
  return 0;
}
