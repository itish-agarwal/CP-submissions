#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int o = 0, z = 0;
    while(n--) {
      int x;
      cin >> x;
      if(x == 0) {
        z++;
      } else {
        o++;
      }
    }
    cout << z << '\n';
  }
  return 0;
}
