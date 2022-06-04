#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif
 
using namespace std;
#define int long long 
const int nax = 1e12 + 677777;
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  set<int> cubes;
  for(int i = 1; i*i*i <= nax; ++i) {
    cubes.insert(i*i*i);
  }
  while(tt--) {
    int n;
    cin >> n;
    bool ok = 0;
    for(int i = 1; i*i*i <= n; ++i) {
      int c1 = i*i*i;
      int c2 = n - c1;
      if(cubes.find(c2) != cubes.end()) {
        cout << "YES\n";
        ok = 1;
        break;
      }
    }
    if(!ok) cout << "NO\n";
  }
}