#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  const int nax = 100;
  vector<int> a(nax);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  for(int i = 3; i < nax; i++) {
    a[i] = a[i-1] + a[i-3];
  }
  while(tt--) {
    int n;
    cin >> n;
    cout << a[n-1] << '\n';
  }
}
