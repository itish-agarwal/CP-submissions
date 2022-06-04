#include <bits/stdc++.h>
 
using namespace std;
 
void rotate_right (vector<int>& a) {
   const int n = a.size();
   vector<int> res (a.begin() + 1, a.end());
   res.push_back (a[0]);
   a = res;
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      vector<int> ans;
      for (int r = 0; r < n - 1; ++r) {
         int loc = 0;
         for (int i = 0; i < n; ++i) {
            if (a[i] == n - r) {
               loc = i;
            }
         }
         if (loc + 1 == n - r) {
            ans.push_back(0);
            continue;
         }
         vector<int> x;
         for (int i = 0; i < n - r; ++i) {
            x.emplace_back (a[i]);
         }
         for (int i = 0; i < loc + 1; ++i) {
            rotate_right(x);
         }
         for (int i = 0; i < n - r; ++i) {
            a[i] = x[i];
         }
         ans.push_back(loc + 1);
      }
      ans.push_back(0);
      reverse(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); ++i) {
         cout << ans[i] << " ";
      }
      cout << '\n';
   }
}