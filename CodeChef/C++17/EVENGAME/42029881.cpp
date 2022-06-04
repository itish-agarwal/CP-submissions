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
    int s = 0;
    while(n--) {
      int x;
      cin >> x;
      s += x;
    }
    if(s % 2) {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}
