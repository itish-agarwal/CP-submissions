#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin >> T;
   while (T--) {
      int64_t N;
      cin >> N;
 
      int64_t c2 = int64_t (sqrt (N));
      while (c2 * c2 > N)
         c2--;
 
      while ((c2 + 1) * (c2 + 1) <= N)
         c2++;
 
      int64_t c3 = int64_t (pow (N, 1.0 / 3));
      while (c3 * c3 * c3 > N)
         c3--;
 
      while ((c3 + 1) * (c3 + 1) * (c3 + 1) <= N)
         c3++;
 
      int64_t c6 = int64_t (pow (N, 1.0 / 6));
      while (c6 * c6 * c6 * c6 * c6 * c6 > N)
         c6--;
 
      while ((c6 + 1) * (c6 + 1) * (c6 + 1) * (c6 + 1) * (c6 + 1) * (c6 + 1) <= N)
         c6++;
 
      cout << c2 + c3 - c6 << '\n';
   }
}