#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   for (int t = 0; t < tt; ++t) {
      string s;
      cin >> s;
      const int n = s.size();
      if (n % 2 == 0 && s.substr (0, n/2) == s.substr (n/2)) {
         cout << "YES" << '\n';
      }
      else {
         cout << "NO" << '\n';
      }
   }
}  