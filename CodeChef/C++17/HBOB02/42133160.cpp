#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> b(n);
  for(auto& it : b) cin >> it;
  vector<int> a(n);
  a[0] = b[0];
  for(int i = 1; i < n; i++) {
    a[i] = (b[i]^b[i-1]);
  }
  --k;
  for(auto it : a) {
    if((it>>k) & 1) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
