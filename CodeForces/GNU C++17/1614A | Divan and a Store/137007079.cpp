#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      if(a[i] >= l && a[i] <= r && a[i] <= k) {
        ans++;
        k -= a[i];
      }
    }
    cout << ans << '\n';
  }
}