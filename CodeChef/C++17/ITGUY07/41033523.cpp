#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int nax = 1e6 + 43434;
vector<int> a(nax);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  a[1] = 0;
  int add = 1;
  for(int i = 2; i < nax; i++) {
    a[i] = a[i-1] + add;
    add++;
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
