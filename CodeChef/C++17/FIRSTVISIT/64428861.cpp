#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   while (tt--) {
      string s, t;
      cin >> s >> t;
      const int n = s.size();
      int lot = 0;
      for (int i = 0; i < n; i += 4) {
         if (s.substr (i, 4) == t) {
            cout << lot + 1 << '\n';
         }
         lot += 1;
      }
   }
}