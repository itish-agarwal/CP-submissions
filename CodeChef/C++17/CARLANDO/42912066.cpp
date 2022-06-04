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
  int tt = 1;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    --n;
    int N = n / 4;
    int ans = 2*N*(N+1);
    N = n / 6;
    ans += 3*N*(N+1);
    N = n / 12;
    ans -= 6*N*(N+1);
    cout << ans << '\n';
  }
}
