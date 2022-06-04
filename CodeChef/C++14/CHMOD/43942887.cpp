#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
  37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
const int nax = 25;

int power(int a, int b, int mod) {
  if(b == 0) return 1;
  int res = power(a, b/2, mod);
  res = (res*res) % mod;
  if(b % 2) {
    res = (res*a) % mod;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> cnt(nax, vector<int> (n, 0));
  for(int j = 0; j < nax; ++j) {
    int p = primes[j];
    for(int i = 0; i < n; ++i) {
      int tt = 0, x = a[i];
      while(x%p == 0) {
        x /= p;
        ++tt;
      }
      cnt[j][i] = tt;
    }
  }
  for(int j = 0; j < nax; ++j) {
    for(int i = 1; i < n; ++i) {
      cnt[j][i] += cnt[j][i-1];
    }
  }
  int qq;
  cin >> qq;
  while(qq--) {
    int l, r, mod;
    cin >> l >> r >> mod;
    --l;
    --r;
    int prod = 1;
    for(int j = 0; j < nax; ++j) {
      int p = primes[j];
      int raise = cnt[j][r] - (l > 0 ? cnt[j][l-1] : 0);
      prod *= power(p, raise, mod);
      prod %= mod;
    }
    cout << prod << '\n';
  }
}
