#include <bits/stdc++.h>

using namespace std;
const int B = 61;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n;
      long long k;
      cin >> n >> k;
      vector<long long> a(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      map<long long, int> mp;
      long long ans = 0;
      for (int i = n - 1; i >= 0; --i) {
         if (k >= a[i]) {
            long long x = k - a[i];
            x ^= a[i];
            ans += mp[x];
         }
         mp[a[i]] += 1;
      }
      cout << ans << '\n';
   }
}