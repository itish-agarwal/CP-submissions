#include <bits/stdc++.h>
 
using namespace std;
#define int long long

void test_case() {
  int n;
  cin >> n;
  int ans = -1;
  for(int a = 1; a*a <= n; ++a) {
    if(n%a == 0) {
      int b = n / a;
      int mn = min(a, b);
      int mx = max(a, b);
      if(mx%2 == mn%2) {
        int y = (mx - mn) / 2;
        if(y) {
          if(ans == -1) ans = y*y;
          else ans = min(ans, y*y);
        }
      }
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}
