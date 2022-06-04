#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n, m;
      cin >> n >> m;
      vector<int> x(m), w(m);
      vector<array<int, 3>> a;
      for (int i = 0; i < m; ++i) {
         cin >> x[i] >> w[i];
         a.push_back ({w[i], x[i], i});
      }
      sort(a.rbegin(), a.rend());
      vector<int> use(m, 1);
      for (int i = 0; i < m - 2 * n; ++i) {
         use[a[i][2]] = 0;
      }
      long long ans = 0;
      vector<int> good;
      for (int i = 0; i < m; ++i) {
         if (use[i]) {
            good.emplace_back (i);
            ans += w[i];
         }
      }
      cout << ans << '\n';
      sort(good.begin(), good.end(), [&] (int i, int j) {
         return x[i] < x[j];
      });
      int l = 0, r = good.size() - 1;
      while (l < r) {
         cout << good[l] + 1 << " " << good[r] + 1 << '\n';
         l += 1;
         r -= 1;
      }
      cout << '\n';
   }
}