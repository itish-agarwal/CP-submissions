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
    vector<int > a(n);
    for(auto& it : a) cin >> it;
    int i = 0, ans = 0, ok = 1;
    while(i < n-1) {
      int x = a[i];
      if(i + x >= n - 1) {
        ++ans;
        i = n - 1;
      } else {
        ++ans;
        int new_jump_point = i;
        int farthest = i + x;
        for(int j = i + 1; j <= i + x; ++j) {
          if(j + a[j] > farthest) {
            new_jump_point = j;
            farthest = j + a[j];
          }
        }
        if(i == new_jump_point) {
          ok = 0;
          break;
        }
        i = new_jump_point;
      }
    }
    if(!ok) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}
    
