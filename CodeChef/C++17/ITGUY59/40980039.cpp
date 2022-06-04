#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int p0 = 0;
    for(int i = 0; i < n; i++) {
      int st = i;
      int has = 0;
      for(int j = 0; j < p0; j++) {
        cout << st;
        st--;
        has++;
      }
      has++;
      cout << 0;
      st = 1;
      while(has < n) {
        cout << st;
        st++;
        has++;
      }
      p0++;
      cout << '\n';
    }
  }
  return 0;
} 
