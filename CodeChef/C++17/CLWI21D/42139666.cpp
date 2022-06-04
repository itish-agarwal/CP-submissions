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
    int n;
    cin >> n;
    int nxt = 1;
    while(nxt*(nxt+1)/2 <= n) {
      nxt++;
    }
    nxt--;
    int ans = nxt*(2*nxt+1)*(nxt+1);
    ans /= 6;
    int rem = n - nxt*(nxt+1)/2;
    ans += rem*(nxt+1);
    cout << ans << '\n';
  }  
  return 0;
}
