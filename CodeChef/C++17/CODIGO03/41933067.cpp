#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int R, n;
    cin >> R >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int in = lower_bound(a.begin(), a.end(), R) - a.begin();
    int el = a[in];
    for(int i = 0; i < n; i++) {
      if(b[i] == el) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
