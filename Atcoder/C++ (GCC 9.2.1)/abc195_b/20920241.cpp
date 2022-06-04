#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int mx = -1, mn = 1e7 + 9;
  for(int n = 0; n <= w; n++) {
    if(a*n <= w && w <= b*n) {
      mx = max(mx, n);
      mn = min(mn, n);
    }
  }
  if(mx == -1) {
    cout << "UNSATISFIABLE\n";
  } else {
    cout << mn << " " << mx << '\n';
  }
}
