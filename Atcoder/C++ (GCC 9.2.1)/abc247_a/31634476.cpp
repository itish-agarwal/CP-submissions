#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin >> s;
   if (s.back() == '1') {
      s.back() = '0';
   }
   for (int i = 2; i >= 0; --i) {
      if (s[i] == '1') {
         s[i] = '0';
         s[i+1] = '1';
      }
   }
   cout << s << endl;
}