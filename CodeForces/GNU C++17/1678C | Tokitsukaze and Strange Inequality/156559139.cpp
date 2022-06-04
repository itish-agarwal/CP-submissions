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
      vector<int> a(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         a[i] -= 1;
      }
      vector<vector<int>> suff (n, vector<int> (n));
      for (int i = 0; i < n; ++i) {
         int smaller = 0;
         for (int j = n - 1; j >= 0; --j) {
            smaller += a[j] < a[i];
            suff[a[i]][j] = smaller;
         }
      }
      vector<vector<int>> pref (n, vector<int> (n));
      for (int i = 0; i < n; ++i) {
         int smaller = 0;
         for (int j = 0; j < n; ++j) {
            smaller += a[j] < a[i];
            pref[a[i]][j] = smaller;
         }
      }
      long long ans = 0;
      for (int b = 1; b < n; ++b) {
         for (int c = b + 1; c + 1 < n; ++c) {
            ans += suff[a[b]][c+1] * pref[a[c]][b-1];
         }
      }
      cout << ans << '\n';
   }
}