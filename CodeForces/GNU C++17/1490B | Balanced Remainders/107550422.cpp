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
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if(x%3 == 0) ++a;
      else if(x%3 == 1) ++b;
      else ++c;
    }
    int N = n / 3;
    int ans = 0;
    for(int i = 0; i < 10; ++i) {
      if(a > N) {
        ans += a - N;
        b += a - N;
        a = N;
      } 
      
      if(b > N) {
        ans += b - N;
        c += b - N;
        b = N;
      }
      
      if(c > N) {
        ans += c - N;
        a += c - N;
        c = N;
      }
    }
    cout << ans << '\n';
  }
}