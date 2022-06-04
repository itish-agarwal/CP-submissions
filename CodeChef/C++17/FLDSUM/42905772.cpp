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
    string s;
    cin >> s;
    int a = s[0] - '0';
    int b = s.back() - '0';
    cout << a + b << '\n';
  }
}
