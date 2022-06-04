#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 10);
    while(m--) {
      int i, j, k;
      cin >> i >> j >> k;
      --i; --j;
      for(int p = i; p <= j; p++) {
        a[p] *= k;
      }
    }
    int s = 0;
    for(int x : a) {
      s += x;
    }
    cout << s/n << '\n';
  }
  return 0;
}
