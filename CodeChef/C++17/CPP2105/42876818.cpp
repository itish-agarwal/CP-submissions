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
    set<int> s;
    s.insert(0);
    while(n--) {
      int x;
      cin >> x;
      vector<int> p;
      for(int xx : s) {
        p.emplace_back(xx);
      }
      s.clear();
      for(int xx : p) {
        s.insert(__gcd(xx, x - 1));
        s.insert(__gcd(xx, x));
        s.insert(__gcd(xx, x + 1));
      }
    }
    cout << *s.rbegin() << '\n';
  }
}
