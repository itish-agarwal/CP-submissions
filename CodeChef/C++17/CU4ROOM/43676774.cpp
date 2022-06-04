#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(n), b(m);
   for(int& x : a) {
      cin >> x;
   }for(int& x : b) {
      cin >> x;
   }
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   int ans = 0;
   int j = 0;
   for(int i = 0; i < n; ++i) {
      
      while(j < m && b[j] < a[i] - k) {
         ++j;
      }
      
      if(j < m && b[j] <= a[i] + k) {
         ++ans;
         ++j;
      }
   }
   
   cout << ans << "\n";
   return 0;
}
