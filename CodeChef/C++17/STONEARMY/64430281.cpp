#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      vector<int64_t> a(n), b(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      for (int i = 0; i < n; ++i) {
         cin >> b[i];
      }
      vector<int> order(n);
      iota (order.begin(), order.end(), 0);
      sort (order.begin(), order.end(), [&](int i, int j) {
         return a[i] - b[i] < a[j] - b[j];
      });
      int64_t ans = 0;
      for (int i = 0; i < n; ++i) {
         int j = order[i];
         ans += a[j] * i + b[j] * (n - i - 1);
      }
      cout << ans << '\n';
   }
}