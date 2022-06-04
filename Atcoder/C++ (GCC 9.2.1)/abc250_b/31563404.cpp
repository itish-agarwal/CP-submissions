#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, a, b;
   cin >> n >> a >> b;

   string x = "", y = "";
   for (int j = 0; j < b; ++j) {
      x.push_back('.');
      y.push_back('#');
   }

   for (int i = 0; i < n; ++i) {
      for (int k = 0; k < a; ++k) {
         for (int j = 0; j < n; ++j) {
            cout << ((i + j) % 2 ? y : x);
         }
         cout << '\n';
      }
   }
}