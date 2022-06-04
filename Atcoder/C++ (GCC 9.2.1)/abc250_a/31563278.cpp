#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m, x, y;
   cin >> n >> m >> x >> y;
   int ans = 0;
   for (int a = 1; a <= n; ++a) {
      for (int b = 1; b <= m; ++b) {
         if (abs (a - x) + abs (b - y) == 1) {
            ans += 1;
         }
      }
   }
   cout << ans << endl;
}