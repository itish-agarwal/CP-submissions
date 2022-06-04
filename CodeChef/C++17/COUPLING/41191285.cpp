#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    if(x == 2) {
      cout << 1 << " ";
    } else {
      x ^= 2;
      cout << x << " ";
    }
  }
  cout << '\n';
  return 0;
}
