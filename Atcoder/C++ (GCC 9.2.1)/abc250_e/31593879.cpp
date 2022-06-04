#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<int> a(n), b(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
   }
   vector<int> sa(n), sb(n);
   set<int> s, t;
   for (int i = 0; i < n; ++i) {
      s.insert (a[i]);
      t.insert (b[i]);
      sa[i] = s.size();
      sb[i] = t.size();
   }
   s.clear();
   t.clear();
   int k = min (sa.back(), sb.back());
   vector<int> newa, newb;
   for (int i = 0; i < n; ++i) {
      if (s.find(a[i]) == s.end()) {
         newa.push_back(a[i]);
         s.insert (a[i]);
      }
      if (t.find(b[i]) == t.end()) {
         newb.push_back(b[i]);
         t.insert (b[i]);
      }
   }
   set<int> S;
   vector<int> dp (k + 1);
   for (int i = 0; i < k; ++i) {
      if (S.find(newa[i]) == S.end()) {
         S.insert (newa[i]);
      }
      else {
         S.erase (newa[i]);
      }
      if (S.find(newb[i]) == S.end()) {
         S.insert (newb[i]);
      }
      else {
         S.erase (newb[i]);
      }
      dp[i + 1] = S.empty();
   }
   int q;
   cin >> q;
   for (int r = 0; r < q; ++r) {
      int x, y;
      cin >> x >> y;
      x -= 1, y -= 1;
      if (sa[x] ^ sb[y]) {
         cout << "No" << '\n';
      }
      else {
         cout << (dp[sa[x]] ? "Yes" : "No") << '\n';
      }
   }
}