#include <bits/stdc++.h>
 
using namespace std;
const int64_t N = 1e9 + 7;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   vector<int64_t> a;
   for (int64_t i = 1; i * i <= N; ++i) {
      a.push_back (i * i);
      if (i * i * i <= N) {
         a.push_back (i * i * i);
      }
   }
 
   sort (a.begin(), a.end());
   a.erase(unique(a.begin(), a.end()), a.end());
 
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n;
      cin >> n;
      int ans = 0;
      for (int j = 0; j < a.size(); ++j) {
         if (a[j] <= n) {
            ans += 1;
         }
      }
      cout << ans << '\n';
   }
}  