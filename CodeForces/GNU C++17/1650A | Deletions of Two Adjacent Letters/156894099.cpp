#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      string s;
      char ch;
      cin >> s >> ch;
      const int n = s.size();
      bool ok = false;
      for (int i = 0; i < n; ++i) {
         if (s[i] == ch) {
            if (i % 2 == 0) {
               ok = true;
            }
         }
      }
      cout << (ok ? "YES" : "NO") << '\n';
   }
}