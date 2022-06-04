#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    long long n, ans = 1;
    cin >> n;
    for(long long i = 1; i <= n; ++i) ans *= i;
    cout << ans << '\n';
  }
}