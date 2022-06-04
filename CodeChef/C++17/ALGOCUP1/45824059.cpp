#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int l, r;
    cin >> l >> r;
    int total = (r*(r+1)/2 - l*(l-1)/2) % mod;
    total = (total * total) % mod;

    constexpr auto power = [](int A, int B) {
      constexpr auto p_mod = [](int A, int B, const auto& P) -> int {
        int res = 1;
        while(B > 0) {
          if(B & 1) res = (res * A) % mod;
          A = (A * A) % mod;
          B /= 2;
        }
        return res;
      };
      return p_mod(A, B, p_mod);
    };

    auto sum_sq = [&](int n) {
      int r = (n * (n + 1)) % mod;
      r = (r * (2*n + 1)) % mod;
      r = (r * power(6LL, mod - 2));
      return r % mod;
    };
    
    int sub = sum_sq(r) - sum_sq(l - 1);
    sub = (sub + mod) % mod;
    total = (total - sub + mod) % mod;
    cout << total << '\n';
  }
}