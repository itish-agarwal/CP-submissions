#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n, x;
      cin >> n >> x;
      int mn = 1e9 + 7, mx = -1;
      for (int i = 0; i < n; ++i) {
         int a;
         cin >> a;
         mn = min (mn, a);
         mx = max (mx, a);
      }
      cout << (x >= mn && x <= mx ? "YES" : "NO") << '\n';
   }
}