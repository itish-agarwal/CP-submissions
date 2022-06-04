#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e4 + 555;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(nax);
  a[1] = 0;
  int nxt = 1;
  for(int i = 2; i < nax; i++) {
    a[i] = a[i-1] + nxt*nxt;
    nxt++;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << a[n] << '\n';
  }
  return 0;
}
