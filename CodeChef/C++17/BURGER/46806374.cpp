#include <bits/stdc++.h>

using namespace std;
#define int long long 

void test_case() {
  int x, y;
  cin >> x >> y;

  if(y%x!=0) {
    cout << "-1\n";
    return;
  }

  int p = y / x;
  //p+i must have exactly i ones in binary
  //representation

  for(int k = 1; k <= 62; k++) {
    int c = p + k;
    int ones = 0;
    while(c>0) {
      ones += c%2;
      c /= 2;
    }
    if(ones == k) {
      int ans = k - 1;
      int bit = 0;
      c = p + k;
      while(c>0) {
        if(c%2) {
          ans += bit;
        }
        c /= 2;
        bit++;
      }
      cout << ans << '\n';
      return;
    }
  }
  cout << "-1\n";
  return;
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