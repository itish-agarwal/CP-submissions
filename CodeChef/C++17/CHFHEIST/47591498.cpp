#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int D, d, P, Q;
    cin >> D >> d >> P >> Q;
    int n = D / d;
    //d*P + d(P+Q) + d*(P+2Q) + ...
    int ans = d*(n*P + (n*(n-1)*Q)/2);
    int rem = D % d;
    ans += rem * (P + n*Q);
    cout << ans << '\n';
  }
}