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
    int x, m, k;
    cin >> x >> m >> k;
    int s = 0;
    while(x--) {
      int a;
      cin >> a;
      s += a;
    }
    cout << min(k, s / m) << '\n';
  }
}
