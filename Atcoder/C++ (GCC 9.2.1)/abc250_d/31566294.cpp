#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int nax = 1e6 + 7;
int pr[nax];

bool is_prime (ll x) {
   for (ll i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
         return 0;
      }
   }

   return 1;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   for (int i = 2; i < nax; ++i) {
      pr[i] = 1;
   }
   for (int p = 2; p < nax; ++p) {
      if (pr[p]) {
         for (int j = 2 * p; j < nax; j += p) {
            pr[j] = 0;
         }
      }
   }

   ll N;
   cin >> N;

   vector<ll> cubes, all;
   for (ll p = 2; p < nax; ++p) {
      if (pr[p]) {
         all.emplace_back(p);
         cubes.emplace_back(p * p * p);
      }
   }

   ll ans = 0;

   for (int i = 0; i < all.size(); ++i) {
      ll p = all[i];
      int l = i + 1;
      
      ll mx = N / p;
      int r = upper_bound (cubes.begin(), cubes.end(), mx) - cubes.begin() - 1;

      ans += max (0, r - l + 1);
   }
   
   cout << ans << endl;
}