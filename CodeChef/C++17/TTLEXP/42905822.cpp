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
    int q, p;
    cin >> q >> p;
    if( q > 1000 ) {
      cout << (p*q*9)/10 << '\n';
    } else {
      cout << p*q << '\n';
    }
  }
}
