#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int mod = 1e9 + 7;

int power(int a, int b) {
  if(b == 0) return 1;
  int res = power(a, b/2);
  res *= res;
  res %= mod;
  if(b % 2) {
    res *= a;
    res %= mod;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;   
    n /= 2;
    n *= (n + 1);
    cout << power(m % mod, n) << '\n';
  }
  return 0;
}
