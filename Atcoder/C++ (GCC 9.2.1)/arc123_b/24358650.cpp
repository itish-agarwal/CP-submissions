#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  int d1 = B - A, d2 = C - B;
  int ans = 0;
  if(d1 > d2) {
    ans = d1 - d2;
  }
  else {
    ans = (d2 - d1) / 2;
    if((d2 - d1) % 2)
      ans += 2;
  }
  cout << ans << '\n';
}