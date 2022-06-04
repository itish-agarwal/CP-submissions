#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int nax = 1e3 + 6;
int cnt[nax];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 0; i < nax; i++) {
    for(int j = 0; j <= i; j++) {
      if((i&j) == 0) {
        cnt[i]++;
      }
    }
  }
  for(int i = 1; i < nax; i++) {
    cnt[i] += cnt[i-1];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n, q;
    cin >> n >> q;
    while(q--) {
      int l, r;
      cin >> l >> r;
      cout << cnt[r] - cnt[l-1] << '\n';
    }
  }
  return 0;
}
