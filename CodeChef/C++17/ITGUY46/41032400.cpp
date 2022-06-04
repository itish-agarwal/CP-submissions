#include <bits/stdc++.h>

using namespace std;
#define int int64_t

//n, n+1, 2n+1 // 6
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = (n-1)*n*(2*n-1);
    ans /= 3;
    ans += n*n;
    cout << ans << '\n';
  }
  return 0;
}
