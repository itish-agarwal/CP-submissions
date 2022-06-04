#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      map<int, int> F;
      for (int i = 0; i < n; ++i) {
         int a;
         cin >> a;
         F[a] += 1;
      }
      int x = 0, y = 0;
      for (auto &it : F) {
         if (it.second == 1) {
            if (x < y) {
               x += 1;
            } else {
               y += 1;
            }
         } else {
            x += 1;
            y += 1;
         }
      }
      if (x < y) {
         x += 1;
      } else if (y < x) {
         y += 1;
      }
      cout << min (x, y) << '\n';
   }
}