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
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    multiset<int> s;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    sort(a.begin(), a.end());
    bool ok = 0;
    for(int x : a) {
      int find = x^X;
      s.erase(s.find(x));
      if(s.find(find)!=s.end()) {
        ok = 1;
        cout << min(x, find) << " " << max(x, find) << '\n';
        break;
      }
      s.insert(x);
    }
    if(!ok) cout << "-1\n";
  }
  return 0;
}
