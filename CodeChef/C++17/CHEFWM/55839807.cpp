#include <bits/stdc++.h>

using namespace std;

int prime_factors(int n) {
  int r = 0;
  for (int x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      r += 1;
      while (n % x == 0) {
        n /= x;
      }
    }
  }
  if (n > 1) {
    r++;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, ans = 0;
    cin >> n >> m;
    int num = prime_factors(m);
    auto update = [&](int d) {
      int cnt = n / d;
      if (cnt <= num) {
        ans = max(ans, cnt);
      }
    };
    for (int x = 1; x * x <= n; ++x) {
      if (n % x == 0) {
        int d1 = x, d2 = n / x;
        update(d1);
        update(d2);
      }
    }
    cout << ans << '\n';
  }
}