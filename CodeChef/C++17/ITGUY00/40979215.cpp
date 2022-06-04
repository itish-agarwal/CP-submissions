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
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int x : a) {
      ans += x%6;
      if(x%6 == 0) {
        ans += 6;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
