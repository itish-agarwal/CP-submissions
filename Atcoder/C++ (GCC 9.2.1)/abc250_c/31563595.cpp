#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, q;
   cin >> n >> q;

   vector<int> a(n), loc(n);

   iota(a.begin(), a.end(), 0);
   iota(loc.begin(), loc.end(), 0);

   for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      --x;

      int y = -1;
      int at = loc[x];

      if (at == n - 1) {
         y = a[n - 2];
      }
      else {
         y = a[at + 1];
      }

      int att = loc[y];
      swap (a[at], a[att]);
      swap (loc[x], loc[y]);
   }

   for (int i = 0; i < n; ++i) {
      cout << a[i] + 1 << " ";
   }
   cout << endl;
}