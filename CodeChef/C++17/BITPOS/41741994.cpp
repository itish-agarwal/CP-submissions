#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r;
    cin >> l >> r;
    while((l | (l+1)) <= r) {
      l = (l | (l+1));
    }
    cout << l << '\n';
  }
  return 0;
}
