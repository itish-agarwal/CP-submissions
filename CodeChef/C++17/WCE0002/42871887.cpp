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
    int d, k;
    cin >> d >> k;
    bool ok = 0;
    for(int i = 0; i*k <= d ;++i) {
      if((d-i*k)%(k-1) == 0) {
        cout << "YES\n";
        ok = 1;
        break;
      }
    }
    if(!ok) cout << "NO\n";
  }  
}
