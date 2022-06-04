#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); 
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      int n, d;
      cin >> n >> d;
      vector<int> a(n);
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      vector<int> segs;
      for (int i = 0; i < n; ++i) {
         segs.emplace_back (a[i] - (i > 0 ? a[i-1] : 0) - 1);
      }
 
      multiset<int> s(segs.begin(), segs.end());
      int ans = 0;
 
      //move to last
      if (a.back() != d) {
         
         for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
               s.erase (s.find(segs.back()));
               s.insert (d - a[n-2] - 1);
 
               ans = max (ans, *s.begin());
 
               s.erase (s.find (d - a[n-2] - 1));
               s.insert (segs.back());
            }
            else {
               s.erase (s.find (segs[i]));
               s.erase (s.find (segs[i+1]));
               s.insert (segs[i] + segs[i+1] + 1);
               s.insert (d - a.back() - 1);
 
               ans = max (ans, *s.begin());
 
               s.erase (s.find (segs[i] + segs[i+1] + 1));
               s.erase (s.find (d - a.back() - 1));
               s.insert (segs[i]);
               s.insert (segs[i+1]);
            }
         }
      }
 
      //move to mid of largest created segment
      for (int i = 0; i < n; ++i) {
         if (i == n - 1) {
            s.erase (s.find (segs.back()));
 
            if (!s.empty()) {
               int max_seg = *s.rbegin() - 1;
               int x = max_seg / 2, y = max_seg - x;
               s.insert (x);
               s.insert (y);
 
               ans = max (ans, *s.begin());
 
               s.erase (s.find (x));
               s.erase (s.find (y));
            }
 
            s.insert (segs.back());
         }
         else {
            s.erase (s.find (segs[i]));
            s.erase (s.find (segs[i+1]));
            s.insert (segs[i] + segs[i+1] + 1);
 
            int max_seg = *s.rbegin() - 1;
            int x = max_seg / 2, y = max_seg - x;
            s.insert (x);
            s.insert (y);
 
            ans = max (ans, *s.begin());
            s.erase (s.find (x));
            s.erase (s.find (y));
 
            s.erase (s.find (segs[i] + segs[i+1] + 1));
            s.insert (segs[i]);
            s.insert (segs[i+1]);
         }
      }
      cout << ans << '\n';
   }
}