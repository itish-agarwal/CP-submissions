#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, x, a = 0, b = 0;
    cin >> n;
    while(n--) {
      cin >> x;
      a += (x % 2);
      b += (x % 2 == 0);
    }
    cout << min(a, b) << '\n';
  }
  return 0;
}
