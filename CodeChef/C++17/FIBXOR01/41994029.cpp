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
    int a, b, n;
    cin >> a >> b >> n;
    n %= 3;
    if(n==0) {
      cout << a << '\n';
    } else if(n==1) {
      cout << b << '\n';
    } else {
      cout << (a^b) << '\n';
    }
  }
  return 0;
}
