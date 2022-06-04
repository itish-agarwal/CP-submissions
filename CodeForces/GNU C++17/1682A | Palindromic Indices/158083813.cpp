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
      string s;
      cin >> s;
      if (n % 2) {
         int l = n / 2, r = n / 2;
         while (l - 1 >= 0 && s[l-1] == s[n/2]) {
            l -= 1, r += 1;
         }
 
         cout << r - l + 1 << '\n';
      } else {
         int l = n / 2 - 1, r = n / 2;
         while (l - 1 >= 0 && s[l-1] == s[n/2]) {
            l -= 1, r += 1;
         }
 
         cout << r - l + 1 << '\n';
      }  
   }
}