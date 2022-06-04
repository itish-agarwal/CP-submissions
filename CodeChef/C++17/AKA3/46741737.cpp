#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int lo = 1, hi = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    hi = max(hi, a[i]);
  }

  auto check = [&](int mid) {
    int r = 0;
    for(int x : a) {
      int cuts = x/mid;
      if(x%mid==0) {
        cuts--;
      }
      r+=cuts;
    }
    return r <= k;
  };

  int ans = hi;
  while(lo<=hi) {
    int mid = (lo+hi)/2;
    if(check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << '\n';

}