#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s;
   cin >> s;
   const int n = s.size();
   set<char> t;
   bool up = false, down = false;
   for (char ch : s) {
      t.insert (ch);
      if (ch >= 'a' && ch <= 'z') {
         down = true;
      }
      else {
         up = true;
      }
   }
   cout << (up && down && t.size() == n ? "Yes" : "No") << endl;
}