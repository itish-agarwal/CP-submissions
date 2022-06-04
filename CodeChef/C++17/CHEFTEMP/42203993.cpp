#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[7], b[7];
  const int n = 7;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += abs(a[i] - b[i]);
  }
  cout << ans << '\n';
}
