#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<string> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int ans = 1e9 + 7;
   for (char c = '0'; c <= '9'; ++c) {
      map<int, int> mp;
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < 10; ++j) {
            if (a[i][j] == c) {
               mp[j] += 1;
            }
         }
      }
      set<int> s;
      for (auto [it, f] : mp) {
         s.insert (it + 10 * (f - 1));
      }
      ans = min (ans, *s.rbegin());
      // ans = min (ans, p);
   }

   cout << ans << endl;
}