#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt;
   cin >> tt;
   while (tt--) {
      int n, a, b;
      cin >> a >> b >> n;
      cout << min (abs (a - b), n - abs (a - b)) << '\n';
   }
}  