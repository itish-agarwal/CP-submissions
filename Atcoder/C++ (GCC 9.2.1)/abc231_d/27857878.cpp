#include <bits/stdc++.h>

using namespace std;

int ceil_div(int a, int b) {
  return a / b + ((a ^ b) > 0 && a % b != 0);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int X, Y;
   cin >> X >> Y;

   if (X >= Y) {
      cout << 0 << '\n';
      return 0;
   }

   cout << ceil_div(Y - X, 10) << '\n';
}