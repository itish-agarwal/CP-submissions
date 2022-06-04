#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int a, b, c, d, e, f, x;
   cin >> a >> b >> c >> d >> e >> f >> x;
   vector<int> j0(x + 1000), j1(x + 1000);
   int i = 1, j = 0;
   while (i <= x) {
      if (j % 2 == 0) {
         for (int k = i; k < i + a; ++k) {
            j0[k] = 1;
         }
         i += a;
      }
      else {
         i += c;
      }
      j += 1;
   }
   i = 1, j = 0;
   while (i <= x) {
      if (j % 2 == 0) {
         for (int k = i; k < i + d; ++k) {
            j1[k] = 1;
         }
         i += d;
      }
      else {
         i += f;
      }
      j += 1;
   }
   int d0 = 0, d1 = 0;
   for (int i = 1; i <= x; ++i) {
      d0 += j0[i] * b;
      d1 += j1[i] * e;
   }
   if (d0 == d1) {
      cout << "Draw" << '\n';
      return 0;
   }
   cout << (d0 > d1 ? "Takahashi" : "Aoki") << '\n';
}