#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = n*n*(n-1)*(n-1);
    ans /= 2;
    ans += n*n*n;
    cout << ans << '\n';
  }
  return 0;
}
