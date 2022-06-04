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
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    int lo = 0, hi = 0;
    for(auto& it : a) {
      cin >> it;
      hi = max(hi, it);
    }
    int ans = lo;
    while(lo <= hi) {
      int mid = (lo + hi)/2;
      int gets = 0;
      for(int x : a) {
        if(x >= mid) {
          gets += x - mid;
        }
      }
      if(gets >= M) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
  }
} 
