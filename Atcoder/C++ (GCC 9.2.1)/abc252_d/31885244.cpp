#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   long long ans = (long long) n * (n - 1) * (n - 2) / 6;
   unordered_map<int, long long> F;
   for (int i = 0; i < n; ++i) {
      F[a[i]] += 1;
   }
   for (auto it : F) {
      long long f = it.second;
      ans -= (n - f) * f * (f - 1) / 2;
      ans -= f * (f - 1) * (f - 2) / 6;
   }
   cout << ans << endl;
}