#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a[3], b[3];
  for(int i = 0; i < 3; ++i) cin >> a[i];
  for(int i = 0; i < 3; ++i) cin >> b[i];
  int x = 0, y = 0;
  for(int i = 0; i < 3; ++i) {
    if(a[i] > b[i]) ++x;
    else if(b[i] > a[i]) ++y;
  }
  cout << x << " " <<y << '\n';
}
