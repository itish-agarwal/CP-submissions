#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    ll x, y, z;
    cin >> x >> y >> z;
    ll r0 = x % z, r1 = y % z;
    if(r0 + r1 < z) {
      cout << x/z + y/z << " 0\n";
    } else {
      cout << x/z + y/z + 1 << " " << min(min(r0, z - r0), min(r1, z - r1)) << '\n';
    }
  }
  return 0;
}
