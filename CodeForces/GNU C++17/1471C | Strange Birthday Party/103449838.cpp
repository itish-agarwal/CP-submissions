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
    vector<int> k(n), c(m);
    for(int i = 0; i < n; i++) {
      cin >> k[i];
      k[i]--;
    }
    for(int i = 0; i < m; i++) {
      cin >> c[i];
    }
    int ans = 0;
    sort(k.begin(), k.end());
    int in = 0;
    for(int i = n-1; i >= 0; i--) {
      if(in <= k[i]) {
        ans += c[in];
        in++;
      } else {
        ans += c[k[i]];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
        