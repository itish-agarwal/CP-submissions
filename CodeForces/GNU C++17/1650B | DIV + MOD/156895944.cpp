#include <bits/stdc++.h>
 
using namespace std;
 
int64_t ceil_div(int64_t a, int64_t b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}
 
int64_t f (int64_t a, int64_t x) {
   return x / a + x % a;
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int64_t l, r, a;
      cin >> l >> r >> a;
      if (l == r) {
         cout << f (a, l) << '\n';
         continue;
      }
      int64_t lo = l / a, hi = r / a, p = -1;
      while (lo <= hi) {
         int64_t m = (lo + hi) / 2;
         if (a * m + a - 1 <= r) {
            lo = m + 1;
            p = m;
         }
         else {
            hi = m - 1;
         }
      }
      if (p > -1) {
         cout << p + a - 1 << '\n';
      }
      else {
         if (r % a == 0) {
            r -= 1;
         }
         int rem = r % a;
         int max_at = r - rem - 1;
         if (max_at >= l) {
            cout << f (a, max_at) << '\n';
         } 
         else {
            cout << f (a, r) << '\n';
         }
      }
   }
}