#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int INF = 2e18 + 777; 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = n-1; i > 0; --i) {
    a[i] -= a[i-1];
  }
  vector<int> b(n + 2);
  while(q--) {
    int l, r, val;
    cin >> l >> r >> val;
    --l; --r;
    b[l] -= val;
    b[r+1] += val;
  }
  for(int i = 1; i <= n+1; i++) {
    b[i] += b[i-1];
  }
  for(int i = 0; i < n; ++i) {
    cout << a[i] + b[i] << " ";
  }
  cout << '\n';
  return 0;
}
