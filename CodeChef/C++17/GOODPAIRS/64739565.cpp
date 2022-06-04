#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n;
      cin >> n;
      vector<int> a(n), b(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      for (int i = 0; i < n; ++i) {
         cin >> b[i];
      }
      map<pair<int, int>, int64_t> mp;
      for (int i = 0; i < n; ++i) {
         mp[{a[i], b[i]}] += 1;
      }
      long long ans = 0;
      set<int> done;
      for (auto [x, y] : mp) {
         int64_t f = mp[{x.second, x.first}];
         if (x.first ^ x.second) {
            ans += f * y;
         }
         else {
            if (done.find (x.first) == done.end()) {
               done.insert (x.first);
               ans += y * (y - 1);
            }
         }
      }
      cout << ans / 2 << '\n';
   }
}