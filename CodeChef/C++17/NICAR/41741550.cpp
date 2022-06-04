#include <bits/stdc++.h>

using namespace std;
#define int long long
  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while(tt--) {
    int n, x;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++) {
      cin >> x;
      cout << x + mx << " ";
      mx = max(mx, x + mx);
    }
    cout << '\n';
  }
  return 0;
}
