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
    int n, k;
    cin >> n >> k;
    --k;
    int ans = 0;
    for(int i = 1; i*i <= n; i++) {
      if(n%i == 0) {
        int d = i, dd = n / i;
        if(d>>k & 1) {
          ans++;
        }
        if(i*i!=n && dd>>k & 1) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
