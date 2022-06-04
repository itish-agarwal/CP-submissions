#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b / 2);
  res = (res * res) % mod;
  if(b & 1) {
    res = (res*a) % mod;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int y;
    cin >> y;
    int n = y * 365LL * 24LL * 60LL * 60LL;
    cout << power(2LL, n) << '\n';
  }
}
