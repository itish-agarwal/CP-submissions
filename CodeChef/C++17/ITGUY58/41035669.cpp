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
    int st = 1;
    for(int i = n; i >= 1; i--) {
      for(int j = 0; j < i; j++) {
        cout << st;
        st++;
      }
      cout << '\n';
    }
  }
  return 0;
}
