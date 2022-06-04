#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   int m = a.back();
   vector<int> cnt (m + 5);
   for (int i = 0; i < n; ++i) {
      cnt[a[i]] += 1;
   }
   long long ans = 0;
   for (int i = 1; i <= m; ++i) {
      for (int y = 1; y <= m / i; ++y) {
         ans += (long long) cnt[i] * cnt[y] * cnt[i * y];
      }
   }
   cout << ans << '\n';
}
