#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto& it : a) cin >> it;
    ll prod = 1;
    int i, j;
    cin >> i >> j;
    int st = min(i, j);
    int en = max(i, j);
    for(int i = st; i < en; i++) {
      prod = (prod * a[i]) % mod;
    }
    cout << prod << '\n';
  }
  return 0;
}
